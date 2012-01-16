/**
    ECE_CITY 2012
    menu_controller.c
    � Jean Guyomarc'h � Maxime Jumeline�� Xavier Brun
**/

#include "../headers/libraries.h"
#include "../headers/defined.h"
#include "../headers/structures.h"
#include "../headers/ece_city.h"

/**********************************************************************
AFFICHE LE COMPORTEMENT DU MENU EN FONCTION DES MOUVEMENTS DE LA SOURIS
**********************************************************************/
void jg_menu_controller(_generale *g) {
    /**
        AFFICHAGE DES MENUS D�ROULANTS (MAIS SANS LA PERSITANCE DE L'EXPLORATION)
    **/

    // Si on survole � Retour au menu �
    if (mouse_x >= 45 && mouse_x < 103 && mouse_y >= 0 && mouse_y <= 21) {
        if (g->m->onClick != 41) {
            g->m->canClickOnMenu = 6;
            clear_to_color(g->m->menubuffer, makecol(255, 0, 255));
            blit(g->m->menu0, g->m->menubuffer, 0, 0, 0, 0, g->m->menu0->w, g->m->menu0->h);
            jg_reload_all(g);
            g->m->onClick = 41;
        }
    }

    // Si on survole � Fichier �
    else if (mouse_x >= 103 && mouse_x < 166 && mouse_y >= 0 && mouse_y <= 21) {
        if (g->m->onClick != 42) {
            g->m->canClickOnMenu = 1;
            clear_to_color(g->m->menubuffer, makecol(255, 0, 255));
            draw_sprite(g->m->menubuffer, g->m->menu1, 0, 0);
            jg_reload_all(g);
            g->m->onClick = 42;
        }
    }

    // Si on survole � Vitesse �
    else if (mouse_x >= 166 && mouse_x < 240 && mouse_y >= 0 && mouse_y <= 21) {
        if (g->m->onClick != 43) {
            g->m->canClickOnMenu = 2;
            clear_to_color(g->m->menubuffer, makecol(255, 0, 255));
            draw_sprite(g->m->menubuffer, g->m->menu2, 0, 0);
            jg_reload_all(g);
            g->m->onClick = 0;
        }
    }

    // Si on survole � Options �
    else if (mouse_x >= 240 && mouse_x < 310 && mouse_y >= 0 && mouse_y <= 21) {
        if (g->m->onClick != 44) {
            g->m->canClickOnMenu = 3;
            clear_to_color(g->m->menubuffer, makecol(255, 0, 255));
            draw_sprite(g->m->menubuffer, g->m->menu3, 0, 0);
            jg_reload_all(g);
            g->m->onClick = 44;
        }
    }

     else if (mouse_x >= 310 && mouse_y <= 21) {
        if (g->m->onClick != 66) {
            g->m->canClickOnMenu = 0;
            jg_draw_menu(g);
            g->m->onClick = 66;
        }
    }

    else if (mouse_x >= 0 && mouse_x < 45 && mouse_y <= 21) {
        if (g->m->onClick != 55) {
            g->m->canClickOnMenu = 0;
            jg_draw_menu(g);
            g->m->onClick = 55;
        }
    }


    /**
        GESTION DE LA PERSISTENCE DES MENUS AU SURVOL (EXPLORATION)
    **/
    else if (g->m->canClickOnMenu == 1 && mouse_x >=103 && mouse_x <= 257 && mouse_y > 20 && mouse_y <= 161) {
        if (mouse_y > 27 && mouse_y <= 45 && g->m->onClick != 1) {
            jg_draw_menu(g);
            draw_sprite(g->m->menubuffer, g->m->menu1_0, 103, 27);
            jg_reload_all(g);
            g->m->onClick = 1;
        }

        if (mouse_y > 45 && mouse_y <= 63 && g->m->onClick != 2) {
            jg_draw_menu(g);
            draw_sprite(g->m->menubuffer, g->m->menu1_1, 103, 45);
            jg_reload_all(g);
            g->m->onClick = 2;
        }

        if (mouse_y > 77 && mouse_y <= 95 && g->m->onClick != 3) {
            jg_draw_menu(g);
            draw_sprite(g->m->menubuffer, g->m->menu1_2, 103, 77);
            jg_reload_all(g);
            g->m->onClick = 3;
        }

        if (mouse_y > 109 && mouse_y <= 134 && g->m->onClick != 4) {
            jg_draw_menu(g);
            draw_sprite(g->m->menubuffer, g->m->menu1_3, 103, 109);
            jg_reload_all(g);
            g->m->onClick = 4;
        }

        if (mouse_y > 139 && mouse_y <= 161 && g->m->onClick != 5) {
            jg_draw_menu(g);
            draw_sprite(g->m->menubuffer, g->m->menu1_4, 103, 139);
            jg_reload_all(g);
            g->m->onClick = 5;
        }
    }

    else if (g->m->canClickOnMenu == 2 && mouse_x >=166 && mouse_x <= 264 && mouse_y > 20 && mouse_y <= 106) {
        if (mouse_y > 27 && mouse_y <= 45 && g->m->onClick != 6) {
            jg_draw_menu(g);
            draw_sprite(g->m->menubuffer, g->m->menu2_0, 166, 27);
            jg_reload_all(g);
            g->m->onClick = 6;
        }

        if (mouse_y > 45 && mouse_y <= 63 && g->m->onClick != 7) {
            jg_draw_menu(g);
            draw_sprite(g->m->menubuffer, g->m->menu2_1, 166, 45);
            jg_reload_all(g);
            g->m->onClick = 7;
        }

        if (mouse_y > 65 && mouse_y <= 84 && g->m->onClick != 8) {
            jg_draw_menu(g);
            draw_sprite(g->m->menubuffer, g->m->menu2_2, 166, 65);
            jg_reload_all(g);
            g->m->onClick = 8;
        }

        if (mouse_y > 84 && mouse_y <= 99 && g->m->onClick != 9) {
            jg_draw_menu(g);
            draw_sprite(g->m->menubuffer, g->m->menu2_3, 166, 84);
            jg_reload_all(g);
            g->m->onClick = 9;
        }
    }
    ///
    /// MENU OPTIONS
    ///
    else if (g->m->canClickOnMenu == 3 && mouse_x >=240 && mouse_x <= 376 && mouse_y > 20 && mouse_y <= 68) {
        if (mouse_y > 27 && mouse_y <= 45 && g->m->onClick != 10) {
            jg_draw_menu(g);
            draw_sprite(g->m->menubuffer, g->m->menu3_0, 240, 27);
            jg_reload_all(g);
            g->m->onClick = 10;
        }

        if (mouse_y > 45 && mouse_y <= 63 && g->m->onClick != 11) {
            jg_draw_menu(g);
            draw_sprite(g->m->menubuffer, g->m->menu3_1, 240, 45);
            jg_reload_all(g);
            g->m->onClick = 11;
        }
    }

    ///
    /// TOUTES LES AUTRES POSITIONS DE LA SOURIS
    ///
    else {
        g->m->canClickOnMenu = 0;
        if (g->m->onClick != 99) {
            clear_bitmap(g->m->menubuffer);
            clear_to_color(g->m->menubuffer, makecol(255, 0, 255));
            blit(g->m->menu, g->m->menubuffer, 0, 0, 0, 0, g->m->menu->w, g->m->menu->h);
            jg_reload_all(g);
            g->m->onClick = 99;
        }
    }



}

void jg_draw_menu(_generale *g) {
    clear_to_color(g->m->menubuffer, makecol(255, 0, 255));

    if (g->m->canClickOnMenu == 0)
        blit(g->m->menu, g->m->menubuffer, 0, 0, 0, 0, g->m->menu->w, g->m->menu->h);

    if (g->m->canClickOnMenu == 1)
        draw_sprite(g->m->menubuffer, g->m->menu1, 0, 0);

    if (g->m->canClickOnMenu == 2)
        draw_sprite(g->m->menubuffer, g->m->menu2, 0, 0);

    if (g->m->canClickOnMenu == 3)
        draw_sprite(g->m->menubuffer, g->m->menu3, 0, 0);

    jg_reload_all(g);
}

void jg_display_menu(_generale *g) {
    draw_sprite(g->buffer, g->m->menubuffer, 0, 0);
}

void mj_display_info(_generale *g) {

}

void mj_display_load(_generale *g) {

}

void mj_display_save(_generale *g) {

}


