#include "Vorb/stdafx.h"
#include "Vorb/ui/script/WidgetScriptFuncs.h"

#include "Vorb/graphics/SpriteFont.h"
#include "Vorb/ui/widgets/Viewport.h"

vui::Viewport* vui::WidgetScriptFuncs::impl::getViewport(IWidget* widget) {
    return widget->getViewport();
}

vui::IWidget* vui::WidgetScriptFuncs::impl::getParent(IWidget* widget) {
    return widget->getParent();
}

f32v4 vui::WidgetScriptFuncs::impl::getDimensions(IWidget* widget) {
    return widget->getDimensions();
}

f32 vui::WidgetScriptFuncs::impl::getX(IWidget* widget) {
    return widget->getX();
}

f32 vui::WidgetScriptFuncs::impl::getY(IWidget* widget) {
    return widget->getY();
}

f32v2 vui::WidgetScriptFuncs::impl::getPosition(IWidget* widget) {
    return widget->getPosition();
}

f32v2 vui::WidgetScriptFuncs::impl::getPaddedPosition(IWidget* widget) {
    return widget->getPaddedPosition();
}

f32 vui::WidgetScriptFuncs::impl::getRelativeX(IWidget* widget) {
    return widget->getRelativeX();
}

f32 vui::WidgetScriptFuncs::impl::getRelativeY(IWidget* widget) {
    return widget->getRelativeY();
}

f32v2 vui::WidgetScriptFuncs::impl::getRelativePosition(IWidget* widget) {
    return widget->getRelativePosition();
}

f32 vui::WidgetScriptFuncs::impl::getWidth(IWidget* widget) {
    return widget->getWidth();
}

f32 vui::WidgetScriptFuncs::impl::getHeight(IWidget* widget) {
    return widget->getHeight();
}

f32v2 vui::WidgetScriptFuncs::impl::getSize(IWidget* widget) {
    return widget->getSize();
}

f32v2 vui::WidgetScriptFuncs::impl::getPaddedSize(IWidget* widget) {
    return widget->getPaddedSize();
}

f32v4 vui::WidgetScriptFuncs::impl::getPadding(IWidget* widget) {
    return widget->getPadding();
}

f32 vui::WidgetScriptFuncs::impl::getPaddingLeft(IWidget* widget) {
    return widget->getPaddingLeft();
}

f32 vui::WidgetScriptFuncs::impl::getPaddingTop(IWidget* widget) {
    return widget->getPaddingTop();
}

f32 vui::WidgetScriptFuncs::impl::getPaddingRight(IWidget* widget) {
    return widget->getPaddingRight();
}

f32 vui::WidgetScriptFuncs::impl::getPaddingBottom(IWidget* widget) {
    return widget->getPaddingBottom();
}

vui::Clipping vui::WidgetScriptFuncs::impl::getClipping(IWidget* widget) {
    return widget->getClipping();
}

vui::ClippingState vui::WidgetScriptFuncs::impl::getClippingLeft(IWidget* widget) {
    return widget->getClippingLeft();
}

vui::ClippingState vui::WidgetScriptFuncs::impl::getClippingTop(IWidget* widget) {
    return widget->getClippingTop();
}

vui::ClippingState vui::WidgetScriptFuncs::impl::getClippingRight(IWidget* widget) {
    return widget->getClippingRight();
}

vui::ClippingState vui::WidgetScriptFuncs::impl::getClippingBottom(IWidget* widget) {
    return widget->getClippingBottom();
}

f32v4 vui::WidgetScriptFuncs::impl::getClipRect(IWidget* widget) {
    return widget->getClipRect();
}

vui::ZIndex vui::WidgetScriptFuncs::impl::getZIndex(IWidget* widget) {
    return widget->getZIndex();
}

vui::Dock vui::WidgetScriptFuncs::impl::getDock(IWidget* widget) {
    return widget->getDock();
}

vui::DockState vui::WidgetScriptFuncs::impl::getDockState(IWidget* widget) {
    return widget->getDockState();
}

f32 vui::WidgetScriptFuncs::impl::getDockSize(IWidget* widget) {
    return widget->getDockSize();
}

nString vui::WidgetScriptFuncs::impl::getName(IWidget* widget) {
    return widget->getName();
}

f32v2 vui::WidgetScriptFuncs::impl::getChildOffset(IWidget* widget) {
    return widget->getChildOffset();
}

f32 vui::WidgetScriptFuncs::impl::getChildOffsetX(IWidget* widget) {
    return widget->getChildOffsetX();
}

f32 vui::WidgetScriptFuncs::impl::getChildOffsetY(IWidget* widget) {
    return widget->getChildOffsetY();
}

vui::WidgetFlags vui::WidgetScriptFuncs::impl::getFlags(IWidget* widget) {
    return widget->getFlags();
}

bool vui::WidgetScriptFuncs::impl::isInBounds(IWidget* widget, f32 x, f32 y) {
    return widget->isInBounds(x, y);
}

bool vui::WidgetScriptFuncs::impl::isEnabled(IWidget* widget) {
    return widget->isEnabled();
}

bool vui::WidgetScriptFuncs::impl::isMouseIn(IWidget* widget) {
    return widget->isMouseIn();
}

bool vui::WidgetScriptFuncs::impl::isClicking(IWidget* widget) {
    return widget->isClicking();
}

bool vui::WidgetScriptFuncs::impl::ignoreOffset(IWidget* widget) {
    return widget->ignoreOffset();
}

bool vui::WidgetScriptFuncs::impl::needsDimensionUpdate(IWidget* widget) {
    return widget->needsDimensionUpdate();
}

bool vui::WidgetScriptFuncs::impl::needsZIndexReorder(IWidget* widget) {
    return widget->needsZIndexReorder();
}

bool vui::WidgetScriptFuncs::impl::needsDockRecalculation(IWidget* widget) {
    return widget->needsDockRecalculation();
}

bool vui::WidgetScriptFuncs::impl::needsClipRectRecalculation(IWidget* widget) {
    return widget->needsClipRectRecalculation();
}

bool vui::WidgetScriptFuncs::impl::needsDrawableRecalculation(IWidget* widget) {
    return widget->needsDrawableRecalculation();
}

vui::PositionType vui::WidgetScriptFuncs::impl::getPositionType(Widget* widget) {
    return widget->getPositionType();
}

vui::Length2 vui::WidgetScriptFuncs::impl::getRawPosition(Widget* widget) {
    return widget->getRawPosition();
}

vui::Length2 vui::WidgetScriptFuncs::impl::getRawSize(Widget* widget) {
    return widget->getRawSize();
}

vui::Length vui::WidgetScriptFuncs::impl::getRawLeft(Widget* widget) {
    return widget->getRawLeft();
}

vui::Length vui::WidgetScriptFuncs::impl::getRawTop(Widget* widget) {
    return widget->getRawTop();
}

vui::Length vui::WidgetScriptFuncs::impl::getRawRight(Widget* widget) {
    return widget->getRawRight();
}

vui::Length vui::WidgetScriptFuncs::impl::getRawBottom(Widget* widget) {
    return widget->getRawBottom();
}
vui::Length2 vui::WidgetScriptFuncs::impl::getRawMinSize(Widget* widget) {
    return widget->getRawMinSize();
}

vui::Length2 vui::WidgetScriptFuncs::impl::getRawMaxSize(Widget* widget) {
    return widget->getRawMaxSize();
}

vui::Length vui::WidgetScriptFuncs::impl::getRawDockSize(Widget* widget) {
    return widget->getRawDockSize();
}

vui::Length4 vui::WidgetScriptFuncs::impl::getRawPadding(Widget* widget) {
    return widget->getRawPadding();
}

vui::Length vui::WidgetScriptFuncs::impl::getRawPaddingLeft(Widget* widget) {
    return widget->getRawPaddingLeft();
}

vui::Length vui::WidgetScriptFuncs::impl::getRawPaddingTop(Widget* widget) {
    return widget->getRawPaddingTop();
}

vui::Length vui::WidgetScriptFuncs::impl::getRawPaddingRight(Widget* widget) {
    return widget->getRawPaddingRight();
}

vui::Length vui::WidgetScriptFuncs::impl::getRawPaddingBottom(Widget* widget) {
    return widget->getRawPaddingBottom();
}

bool vui::WidgetScriptFuncs::impl::addWidget(IWidget* widget, IWidget* child) {
    return widget->addWidget(child);
}

bool vui::WidgetScriptFuncs::impl::removeWidget(IWidget* widget, IWidget* child) {
    return widget->removeWidget(child);
}

void vui::WidgetScriptFuncs::impl::setX(IWidget* widget, f32 x) {
    widget->setX(x);
}

void vui::WidgetScriptFuncs::impl::setY(IWidget* widget, f32 y) {
    widget->setY(y);
}

void vui::WidgetScriptFuncs::impl::setPosition(IWidget* widget, f32v2 pos) {
    widget->setPosition(pos);
}

void vui::WidgetScriptFuncs::impl::setRelativeX(IWidget* widget, f32 relX) {
    widget->setRelativeX(relX);
}

void vui::WidgetScriptFuncs::impl::setRelativeY(IWidget* widget, f32 relY) {
    widget->setRelativeY(relY);
}

void vui::WidgetScriptFuncs::impl::setRelativePosition(IWidget* widget, f32v2 position) {
    widget->setRelativePosition(position);
}

void vui::WidgetScriptFuncs::impl::setWidth(IWidget* widget, f32 width) {
    widget->setWidth(width);
}

void vui::WidgetScriptFuncs::impl::setHeight(IWidget* widget, f32 height) {
    widget->setHeight(height);
}

void vui::WidgetScriptFuncs::impl::setSize(IWidget* widget, f32v2 size) {
    widget->setSize(size);
}

void vui::WidgetScriptFuncs::impl::setPadding(IWidget* widget, f32v4 padding) {
    widget->setPadding(padding);
}

void vui::WidgetScriptFuncs::impl::setPaddingLeft(IWidget* widget, f32 left) {
    widget->setPaddingLeft(left);
}

void vui::WidgetScriptFuncs::impl::setPaddingTop(IWidget* widget, f32 top) {
    widget->setPaddingTop(top);
}

void vui::WidgetScriptFuncs::impl::setPaddingRight(IWidget* widget, f32 right) {
    widget->setPaddingRight(right);
}

void vui::WidgetScriptFuncs::impl::setPaddingBottom(IWidget* widget, f32 bottom) {
    widget->setPaddingBottom(bottom);
}

void vui::WidgetScriptFuncs::impl::setClipping(IWidget* widget, Clipping clipping) {
    widget->setClipping(clipping);
}

void vui::WidgetScriptFuncs::impl::setClippingLeft(IWidget* widget, ClippingState state) {
    widget->setClippingLeft(state);
}

void vui::WidgetScriptFuncs::impl::setClippingTop(IWidget* widget, ClippingState state) {
    widget->setClippingTop(state);
}

void vui::WidgetScriptFuncs::impl::setClippingRight(IWidget* widget, ClippingState state) {
    widget->setClippingRight(state);
}

void vui::WidgetScriptFuncs::impl::setClippingBottom(IWidget* widget, ClippingState state) {
    widget->setClippingBottom(state);
}

void vui::WidgetScriptFuncs::impl::setZIndex(IWidget* widget, ZIndex zIndex) {
    widget->setZIndex(zIndex);
}

void vui::WidgetScriptFuncs::impl::setDock(IWidget* widget, Dock dock) {
    widget->setDock(dock);
}

void vui::WidgetScriptFuncs::impl::setDockState(IWidget* widget, DockState state) {
    widget->setDockState(state);
}

void vui::WidgetScriptFuncs::impl::setDockSize(IWidget* widget, f32 size) {
    widget->setDockSize(size);
}

void vui::WidgetScriptFuncs::impl::setName(IWidget* widget, nString name) {
    widget->setName(name);
}

void vui::WidgetScriptFuncs::impl::setChildOffset(IWidget* widget, f32v2 offset) {
    widget->setChildOffset(offset);
}

void vui::WidgetScriptFuncs::impl::setChildOffsetX(IWidget* widget, f32 offset) {
    widget->setChildOffsetX(offset);
}

void vui::WidgetScriptFuncs::impl::setChildOffsetY(IWidget* widget, f32 offset) {
    widget->setChildOffsetY(offset);
}

void vui::WidgetScriptFuncs::impl::setFlags(IWidget* widget, WidgetFlags flags) {
    widget->setFlags(flags);
}

void vui::WidgetScriptFuncs::impl::setIgnoreOffset(IWidget* widget, bool ignoreOffset) {
    widget->setIgnoreOffset(ignoreOffset);
}

void vui::WidgetScriptFuncs::impl::setNeedsDimensionUpdate(IWidget* widget, bool flag) {
    widget->setNeedsDimensionUpdate(flag);
}

void vui::WidgetScriptFuncs::impl::setNeedsZIndexReorder(IWidget* widget, bool flag) {
    widget->setNeedsZIndexReorder(flag);
}

void vui::WidgetScriptFuncs::impl::setNeedsDockRecalculation(IWidget* widget, bool flag) {
    widget->setNeedsDockRecalculation(flag);
}

void vui::WidgetScriptFuncs::impl::setNeedsClipRectRecalculation(IWidget* widget, bool flag) {
    widget->setNeedsClipRectRecalculation(flag);
}

void vui::WidgetScriptFuncs::impl::setNeedsDrawableRecalculation(IWidget* widget, bool flag) {
    widget->setNeedsDrawableRecalculation(flag);
}

void vui::WidgetScriptFuncs::impl::setPositionType(Widget* widget, PositionType positionType) {
    widget->setPositionType(positionType);
}

void vui::WidgetScriptFuncs::impl::setRawPosition(Widget* widget, Length2 position) {
    widget->setRawPosition(position);
}

void vui::WidgetScriptFuncs::impl::setRawSize(Widget* widget, Length2 size) {
    widget->setRawSize(size);
}

void vui::WidgetScriptFuncs::impl::setLeft(Widget* widget, f32 left) {
    widget->setLeft(left);
}

void vui::WidgetScriptFuncs::impl::setTop(Widget* widget, f32 top) {
    widget->setTop(top);
}

void vui::WidgetScriptFuncs::impl::setRight(Widget* widget, f32 right) {
    widget->setRight(right);
}

void vui::WidgetScriptFuncs::impl::setBottom(Widget* widget, f32 bottom) {
    widget->setBottom(bottom);
}

void vui::WidgetScriptFuncs::impl::setRawLeft(Widget* widget, Length left) {
    widget->setRawLeft(left);
}

void vui::WidgetScriptFuncs::impl::setRawTop(Widget* widget, Length top) {
    widget->setRawTop(top);
}

void vui::WidgetScriptFuncs::impl::setRawRight(Widget* widget, Length right) {
    widget->setRawRight(right);
}

void vui::WidgetScriptFuncs::impl::setRawBottom(Widget* widget, Length bottom) {
    widget->setRawBottom(bottom);
}

void vui::WidgetScriptFuncs::impl::setMinSize(Widget* widget, f32v2 minSize) {
    widget->setMinSize(minSize);
}

void vui::WidgetScriptFuncs::impl::setMaxSize(Widget* widget, f32v2 maxSize) {
    widget->setMaxSize(maxSize);
}

void vui::WidgetScriptFuncs::impl::setRawMinSize(Widget* widget, Length2 minSize) {
    widget->setRawMinSize(minSize);
}

void vui::WidgetScriptFuncs::impl::setRawMaxSize(Widget* widget, Length2 maxSize) {
    widget->setRawMaxSize(maxSize);
}

void vui::WidgetScriptFuncs::impl::setRawDockSize(Widget* widget, Length dockSize) {
    widget->setRawDockSize(dockSize);
}

void vui::WidgetScriptFuncs::impl::setRawPadding(Widget* widget, Length4 padding) {
    widget->setRawPadding(padding);
}

void vui::WidgetScriptFuncs::impl::setRawPaddingLeft(Widget* widget, Length left) {
    widget->setRawPaddingLeft(left);
}

void vui::WidgetScriptFuncs::impl::setRawPaddingTop(Widget* widget, Length top) {
    widget->setRawPaddingTop(top);
}

void vui::WidgetScriptFuncs::impl::setRawPaddingRight(Widget* widget, Length right) {
    widget->setRawPaddingRight(right);
}

void vui::WidgetScriptFuncs::impl::setRawPaddingBottom(Widget* widget, Length bottom) {
    widget->setRawPaddingBottom(bottom);
}
