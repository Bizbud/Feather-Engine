#include "sprite.h"
#include <SDL2/SDL_image.h>

void sprite_render(const Camera *cam)
{
    for(int i = 0; i < MAX_SPRITES; i++)
    {
        if(sprites[i] != NULL)
        {
            sprites[i]->dst.x = 0;
            sprites[i]->dst.y = 0;

            Transform *root_parent = sprites[i]->transform.parent;
            while(root_parent != NULL)
            {
                sprites[i]->dst.x += root_parent->x;
                sprites[i]->dst.y += root_parent->y;
                root_parent = root_parent->parent;
            }

            sprites[i]->dst.x += cam->pos.x;
            sprites[i]->dst.y += cam->pos.y;
            SDL_RenderCopy(cam->renderer, sprites[i]->tex, NULL, &sprites[i]->dst);
        }
    }
}

Sprite sprite_init(char *tex_path, Transform sprite_transform, const Camera *cam)
{
    Sprite new_sprite;
    new_sprite.active = 1;
    new_sprite.transform = sprite_transform;
    new_sprite.tex = IMG_LoadTexture(cam->renderer, tex_path);
    int w, h;
    SDL_QueryTexture(new_sprite.tex, NULL, NULL, &w, &h);
    new_sprite.dst.w = w;
    new_sprite.dst.h = h;
    new_sprite.dst.x = 0;
    new_sprite.dst.y = 0;
    return new_sprite; 
}

void sprite_add(Sprite *sprite)
{
    for(int i = 0; i < MAX_SPRITES; i++)
    {
        if(sprites[i] == NULL || sprites[i]->active == 0)
        {
            sprite->active = 1;
            sprites[i] = sprite;
            return;
        }
    }
}

void sprite_remove(Sprite *sprite)
{
    sprite->active = 0;
}