//
// IEnvironment.h
// Vorb Engine
//
// Created by Matthew Marshall on 8 Nov 2018
// Copyright 2018 Regrowth Studios
// MIT License
//

/*! \file IEnvironment.h
 * \brief Interface for scripting environments.
 * 
 * Script environments act like databases. They track and manage
 * all scripted function pointers. They also provide functions
 * to register C++ callbacks for scripts to use, in addition to
 * functions to register events for script functions to subscribe to.
 */

// TODO(Matthew): Investigate how to apply application control over the amount of time dedicated to executing scripts, including 
//                time spent executing script callbacks subscribed to events.
// TODO(Matthew): Simplify templating when (if) we shift to C++17.

#pragma once

#ifndef Vorb_IEnvironment_h__
//! @cond DOXY_SHOW_HEADER_GUARDS
#define Vorb_IEnvironment_h__
//! @endcond

#ifdef VORB_USING_SCRIPT

#include <unordered_map>

#include "../Event.hpp"
#include "../io/Path.h"

namespace vorb {
    namespace script {
        using GenericScriptFunction = void*;
        using GenericCFunction      = void(*)();

        // TODO(Matthew): A static_assert of implementations providing functions required?
        template <typename EnvironmentImpl>
        class IEnvironment {
        protected:
            using CFunctionList = std::vector<std::unique_ptr<DelegateBase>>;
            using EventAdder    = void(EnvironmentImpl::*)(GenericScriptFunction, EventBase*);
            struct EventData {
                EventBase* event;
                EventAdder adder;
            };
            using EventList = std::unordered_map<nString, EventData>;
        public:
            IEnvironment() :
                m_maxScriptLength(INT_MAX) {
                static_assert(std::is_base_of<IEnvironment, EnvironmentImpl>::value, "Environment implementation provided not deriving from IEnvironment interface.");
            }
            virtual ~IEnvironment() { /* Empty */ }

            /*!
             * \brief Initialises the environment.
             */
            virtual void init() = 0;
            /*!
             * \brief Initialises the environment.
             *
             * \param filepath The filepath from which to load the script.
             */
            virtual void init(const vio::Path& filepath) = 0;

            /*!
             * \brief Disposes of the environment.
             */
            virtual void dispose() {
                for (auto& cFunction : m_cFunctions) {
                    cFunction.reset();
                }
                CFunctionList().swap(m_cFunctions);
                EventList().swap(m_events);
                m_listenerPool.dispose();
            }

            /*!
             * \brief Load in a script from the provided filepath.
             *
             * \param filepath The filepath from which to load the script.
             */
            virtual bool load(const vio::Path& filepath) = 0;
            /*!
             * \brief Load in the provided script string.
             *
             * \param script A string of script to load into the script environment.
             */
            virtual bool load(const nString& script) = 0;

            /*!
             * \brief Runs everything already loaded into the script environment.
             */
            virtual bool run() = 0;
            /*!
             * \brief Loads in the script at the provided filepath, then runs it.
             *
             * Anything loaded in before this call will also be ran if no other calls to run have been made since.
             *
             * \param filepath The filepath from which to load the script.
             */
            virtual bool run(const vio::Path& filepath) = 0;
            /*!
             * \brief Loads in the provided script string, then runs it.
             *
             * Anything loaded in before this call will also be ran if no other calls to run have been made since.
             *
             * \param script A string of script to load into the script environment.
             */
            virtual bool run(const nString& script) = 0;

            /*!
             * \brief Add a C++ delegate as a hook with name "name" for Lua scripts to call.
             *
             * Note that this instance is here to act as a fake virtualisation of member template.
             *
             * \param name The name of the delegate to add.
             * \param function The delegate to add.
             */
            template <typename ReturnType, typename ...Parameters>
            void addCDelegate(const nString& name, Delegate<ReturnType, Parameters...>&& delegate) {
                static_cast<EnvironmentImpl*>(this)->addCDelegate(name, std::move(delegate));
            }

            /*!
             * \brief Returns a pointer delegate wrapping the named script function.
             *
             * \tparam ReturnType The return type of the script function.
             * \tparam Parameters The parameters accepted by the script funciton.
             *
             * \param name The name of the script function.
             * \param create Whether to try to create a register for the script function named if it isn't already registered.
             *
             * \return A pointer to the delegate, or nullptr if the script function wasn't found.
             */
            template <typename ReturnType, typename ...Parameters>
            CALLER_DELETE Delegate<ReturnType, Parameters...> getScriptDelegate(const nString& name, bool create = true) {
                return static_cast<EnvironmentImpl*>(this)->template getScriptDelegate<ReturnType, Parameters...>(name, create);
            }

            /*!
             * \brief Adds the given value to the top of the lua stack.
             *
             * Note that this instance is here to act as a fake virtualisation of member template.
             *
             * \param name The key to give the value to be added to the Lua stack.
             * \param value The value to add to the Lua stack.
             */
            template <typename Type>
            bool addValue(const nString& name, Type value) {
                return static_cast<EnvironmentImpl*>(this)->addValue(name, std::move(value));
            }

            /*!
             * \brief Set the max length each script may be.
             *
             * \param length The max length.
             */
            void setMaxScriptLength(i32 length) { m_maxScriptLength = length; }

            /*!
             * \brief Get the max length each script may be.
             *
             * \return The max length.
             */
            i32 getMaxScriptLength() { return m_maxScriptLength; }

            /*!
             * \brief Sets a series of embedded lua tables to the top of the lua stack.
             *
             * Note that this instance is here to act as a fake virtualisation of member template.
             *
             * \param namespaces The namespaces to set.
             */
            template<typename ...Namespaces>
            void setNamespaces(Namespaces... namespaces) {
                static_cast<EnvironmentImpl*>(this)->setNamespaces(std::forward<Namespaces>(namespaces)...);
            }
        protected:
            i32              m_maxScriptLength; ///< The maximum length a single script may be.
            CFunctionList    m_cFunctions;      ///< List of C++ functions registered with the script environment.
            EventList        m_events;          ///< List of events registered with the script environment.
            AutoDelegatePool m_listenerPool;    ///< Manages Lua functions subscribed to events.
        };
    }
}
namespace vscript = vorb::script;

#endif // VORB_USING_SCRIPT

#endif // !Vorb_IEnvironment_h__
