/*
 * (C) 2001-2012 Marmalade. All Rights Reserved.
 *
 * This document is protected by copyright, and contains information
 * proprietary to Marmalade.
 *
 * This file consists of source code released by Marmalade under
 * the terms of the accompanying End User License Agreement (EULA).
 * Please do not use this program/source code before you have read the
 * EULA and have agreed to be bound by its terms.
 */

#include "resources.h"
#include "Iw2D.h"


Resources::Resources()
{
    // Load images
    Gem = Iw2DCreateImage("textures/sparkle_tomato.png");
    MenuBG = Iw2DCreateImage("textures/boekarest.png");
    GameBG = Iw2DCreateImage("textures/venetie.png");
    MenuButton = Iw2DCreateImage("textures/button_bg.png");
    Placard = Iw2DCreateImage("textures/placard.png");
    PauseIcon = Iw2DCreateImage("textures/pause_icon.png");
    PlayButton = Iw2DCreateImage("textures/play.png");

    // Load fonts
    Font = Iw2DCreateFont("fonts/arial8.gxfont");

    // Create gem atlas
    int frame_w = (int)(Gem->GetWidth() / 5);
    int frame_h = (int)(Gem->GetHeight() / 3);
    GemAtlas = new CAtlas(frame_w, frame_h, 15, Gem);
}

Resources::~Resources()
{
    delete GemAtlas;
    delete Gem;
    delete MenuBG;
    delete GameBG;
    delete MenuButton;
    delete PauseIcon;
    delete Placard;
    delete PlayButton;
    delete Font;
}

// Global resources
Resources* g_pResources = 0;



