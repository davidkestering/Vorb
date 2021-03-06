//
// lua/Environment.h
// Vorb Engine
//
// Created by Matthew Marshall on 8 Nov 2018
// Based on Cristian Zaloj's prior script environment.
// Copyright 2018 Regrowth Studios
// MIT License
//

/*! \file Environment.h
 * \brief Lua implementation of the script environment.
 */

// TODO(Matthew): Investigate lua_yield and lua_resume for coroutines.
// TODO(Matthew): Investigate lua_newthread for having separate locals for each mod while sharing globals.
//                    This could be good for mods.
// TODO(Matthew): Handle errors.

#pragma once

#ifndef Vorb_Lua_Environment_h__
//! @cond DOXY_SHOW_HEADER_GUARDS
#define Vorb_Lua_Environment_h__
//! @endcond

#ifdef VORB_USING_SCRIPT

#include <lua.hpp>

namespace vorb {
    namespace script {
        namespace lua {
            using Handle = lua_State*; ///< The Lua state handle.
        }
    }
}

#include "CFunction.hpp"
#include "LFunction.h"
#include "../IEnvironment.hpp"

namespace vorb {
    namespace script {
        namespace lua {
            class LFunction;

            class Environment : public IEnvironment<Environment> {
                using LFunctionList = std::unordered_map<nString, LFunction*>;

                friend int registerLFunction(Handle state);
            public:
                Environment();
                Environment(const nString& filepath);
                virtual ~Environment() { /* Empty */ }

                /*!
                 * \brief Initialises the environment.
                 */
                virtual void init() override;
                /*!
                 * \brief Initialises the environment.
                 *
                 * \param filepath The filepath from which to load the script.
                 */
                virtual void init(const vio::Path& filepath) override;

                /*!
                 * \brief Disposes of the environment.
                 */
                virtual void dispose() override;

                /*!
                 * \brief Load in a script from the provided filepath.
                 *
                 * \param filepath The filepath from which to load the script.
                 */
                virtual bool load(const vio::Path& filepath) override;

                /*!
                * \brief Load in the provided script string.
                *
                * \param script A string of script to load into the script environment.
                */
                virtual bool load(const nString& script) override;

                /*!
                * \brief Runs everything already loaded into the script environment.
                */
                virtual bool run() override;

                /*!
                * \brief Loads in the script at the provided filepath, then runs it.
                *
                * Anything loaded in before this call will also be ran if no other calls to run have been made since.
                *
                * \param filepath The filepath from which to load the script.
                */
                virtual bool run(const vio::Path& filepath) override;

                /*!
                * \brief Loads in the provided script string, then runs it.
                *
                * Anything loaded in before this call will also be ran if no other calls to run have been made since.
                *
                * \param script A string of script to load into the script environment.
                */
                virtual bool run(const nString& script) override;

                /*!
                 * \brief Add a C++ delegate as a hook with name "name" for Lua scripts to call.
                 *
                 * \param name The name of the delegate to add.
                 * \param function The delegate to add.
                 */
                template<typename ReturnType, typename ...Parameters>
                void addCDelegate(const nString& name, Delegate<ReturnType, Parameters...>&& delegate);

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
                CALLER_DELETE Delegate<ReturnType, Parameters...> getScriptDelegate(const nString& name, bool create = true);

                /*!
                 * \brief Adds the given value to the top of the lua stack.
                 *
                 * \param name The key to give the value to be added to the Lua stack.
                 * \param value The value to add to the Lua stack.
                 */
                template<typename Type>
                bool addValue(const nString& name, Type value);

                /*!
                 * \brief Sets the global lua table to the top of the lua stack.
                 */
                void setGlobalNamespace();
                /*!
                 * \brief Sets a series of embedded lua tables to the top of the lua stack.
                 *
                 * \param namespaces The namespaces to set.
                 */
                template<typename ...Namespaces>
                void setNamespaces(Namespaces... namespaces);

                /*!
                 * \brief Returns the Lua handle.
                 *
                 * \return The Lua handle.
                 */
                Handle getHandle() { return m_state; }
            protected:
                VORB_NON_COPYABLE(Environment);

                // TODO(Matthew): Can addCFunction and addCClosure be generalised for the interface?
                /*!
                 * \brief Add a C++ function as a hook with name "name" for Lua scripts to call.
                 *
                 * \param name The name of the function to add.
                 * \param function The function to add.
                 *
                 * Warning: function must satisfy the signature int(*)(lua_State*).
                 */
                void addCFunction(const nString& name, CFunction::Type function);
                /*!
                 * \brief Add a C++ function that captures upvalueCount many upvalues - variables accessible at every call of the function.
                 *
                 * \param name The name of the function to add as a closure.
                 * \param upvalueCount The number of values at the top of the Lua stack to capture in this closure.
                 * \param function The function to add.
                 *
                 * Warning: function must satisfy the signature int(*)(lua_State*).
                 */
                void addCClosure(const nString& name, ui8 upvalueCount, CFunction::Type function);


                /*!
                * \brief Makes an LFunction instance from the given name.
                *
                * \param name The name of the Lua function to create an LFunction register of.
                *
                * \return The success code (0 for success, negative for failure).
                */
                i32 makeLFunction(const nString& name);

                /*!
                 * \brief Add a Lua function to the list of registered Lua functions.
                 *
                 * \param lFunction The Lua function to register.
                 *
                 * \return True on successful register, false otherwise.
                 */
                bool addLFunction(LFunction* lFunction);

                /*!
                 * \brief Retrieves the named Lua function from the registered list.
                 *
                 * \param lFunction The Lua function to register.
                 *
                 * \return Pointer to the function obtained, or nullptr if not found.
                 */
                LFunction* getLFunction(const nString& name);

                /*!
                 * \brief Recursively pushes tables onto the top of the lua stack.
                 *
                 * \param namespace The namespaces to push now.
                 * \param namespaces The namespaces to push next.
                 */
                template<typename Namespace, typename ...Namespaces>
                void pushNamespaces(Namespace namespace_, Namespaces... namespaces);
                /*!
                 * \brief Specialisation to complete this recursive loop.
                 */
                inline void pushNamespaces() {
                    // Empty
                }
                /*!
                 * \brief Pushes the specific namespace given to the Lua stack.
                 *
                 * \param namespace The namespaces to push.
                 */
                void pushNamespace(const nString& namespace_);

                Handle        m_state;           ///< The Lua state handle.
                i32           m_namespaceDepth;  ///< The depth of namespace we are currently at.
                LFunctionList m_lFunctions;      ///< The list of Lua functions registered with this environment.
            };

            /*!
             * \brief Dumps the lua stack to cout.
             *
             * //TODO(Matthew): Yield choice of output mode to caller?
             */
            void dumpStack();

            /*!
             * \brief Makes an LFunction instance from a registering Lua function.
             *
             * \param state The Lua state handle managing the script the registering function is from.
             *
             * \return The number of elements returned to the Lua stack.
             */
            int registerLFunction(Handle state);
        }
    }
}
namespace vscript = vorb::script;

template<typename ReturnType, typename ...Parameters>
inline void vscript::lua::Environment::addCDelegate(const nString& name, Delegate<ReturnType, Parameters...>&& delegate) {
    // Create copy of delegate and store it.
    m_cFunctions.emplace_back(new Delegate<ReturnType, Parameters...>(std::move(delegate)));

    // Get function to wrap delegate.
    CFunction::Type function = CFunction::fromDelegate<ReturnType, Parameters...>();

    // Push pointer to delegate onto stack and then make a closure of the wrapping function that captures the delegate.
    ValueMediator<void*>::push(m_state, m_cFunctions.back().get());
    addCClosure(name, 1, function);
}

template<typename Type>
inline bool vscript::lua::Environment::addValue(const nString& name, Type value) {
    // See if a field already exists with the key of this value.
    lua_getfield(m_state, -1, name.c_str());
    // If it doesn't, we can add it.
    if (lua_isnil(m_state, -1)) {
        // Pop the result of looking for a populated key.
        lua_pop(m_state, 1);
        // Push value and set a field of key name to hold that value.
        ValueMediator<Type>::push(m_state, value);
        lua_setfield(m_state, -2, name.c_str());
        // Success
        return true;
    }
    // Pop the result of looking for a populated key.
    //     Note this is different to the case in pushNamespace as while in that case finding a
    //     field already exists or creating one are both successes, in the case of adding a value
    //     we have failed if the field we want to add it to already exists.
    lua_pop(m_state, 1);
    // Fail
    return false;
}

template<typename ...Namespaces>
inline void vscript::lua::Environment::setNamespaces(Namespaces... namespaces) {
    // TODO(Matthew): Does popping like this actually work? Some things may be pushed onto stack above namespaces...
    // Pop any namespaces currently set.
    if (m_namespaceDepth > 0) {
        lua_pop(m_state, m_namespaceDepth);
    }
    // Push the new namespaces onto stack.
    pushNamespaces(namespaces...);
    // Set the new namespace depth.
    m_namespaceDepth = sizeof...(Namespaces);
}

template<typename Namespace, typename ...Namespaces>
inline void vscript::lua::Environment::pushNamespaces(Namespace namespace_, Namespaces... namespaces) {
    // Recursive solution to unpack variadic namespaces.
    // Should be good enough solution given the insane depth of namespaces needed to cause stack overflow.
    pushNamespace(namespace_);
    pushNamespaces(namespaces...);
}

/*!
 * \brief Workaround for MSVC being shit. Constructs the appropriate delegate for the given LFunction and desired signature.
 *
 * \tparam ReturnType The type the delegate returns.
 * \tparam Paramaters The types of the parameters the delegate takes for invocation.
 *
 * \param lFunction The Lua function to make a delegate for.
 *
 * \return The delegate made.
 */
template <typename ReturnType, typename ...Parameters,
            typename = typename std::enable_if<!std::is_same<void, ReturnType>::value>::type>
Delegate<ReturnType, Parameters...> makeScriptDelegate(vscript::lua::LFunction* lFunction) {
    // Construct returning LFunction.
    vscript::lua::SRLFunction<ReturnType> srlFunction = lFunction->template withSingleReturn<ReturnType>();

    return makeConstFunctor<ReturnType, Parameters...>(srlFunction);
}
template <typename ReturnType, typename ...Parameters,
            typename = typename std::enable_if<std::is_same<void, ReturnType>::value>::type>
Delegate<void, Parameters...> makeScriptDelegate(vscript::lua::LFunction* lFunction) {
    return makeConstDelegate<void, Parameters...>(lFunction);
}

// TODO(Matthew): Support multiple return types.
template <typename ReturnType, typename ...Parameters>
Delegate<ReturnType, Parameters...> vscript::lua::Environment::getScriptDelegate(const nString& name, bool create /*= true*/) {
    // Get the LFunction we want to wrap.
    LFunction* lFunction = getLFunction(name);

    // If we couldn't find it, try to make it.
    if (lFunction == nullptr) {
        // If we couldn't make it, fail.
        if (!create || makeLFunction(name) != 0) return NilDelegate<ReturnType, Parameters...>;

        lFunction = getLFunction(name);
    }
    
    return makeScriptDelegate<ReturnType, Parameters...>(lFunction);
}

#endif // VORB_USING_SCRIPT

#endif // !Vorb_Lua_Environment_h__
