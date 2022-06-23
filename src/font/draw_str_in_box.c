/**
 ** @file draw_str_in_box.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "font.h"

void draw_str_in_box(t_bunny_buffer *buf,
                     t_bunny_font *font,
                     char *str,
                     t_bunny_area area)
{
    size_t max_len;
    t_bunny_position pos;
    size_t index;
    size_t i;
    size_t last;
    char *split_str;

    max_len = area.w / (font->glyph_size.y * FONT_RATIO);
    pos = SETPOS(area.x, area.y);
    index = 0;
    i = 0;
    last = 0;
    while (str[i] != '\0')
    {
        if ((str[i] == ' ' && i - index < max_len + 1) ||
            str[i] == '\n' || str[i + 1] == '\0')
        {
            last = i;
        }
        if (i - index > max_len + 1 ||
            str[i] == '\n' || str[i + 1] == '\0')
        {
            split_str = term_strndup(&str[index], last - index + 1);
            if (pos.y + font->glyph_size.y < area.y + area.h)
            {
                draw_str(buf, font, split_str, pos);
            }
            pos.y += font->glyph_size.y;
            index = last + 1;
            free(split_str);
        }
        ++i;
    }
}