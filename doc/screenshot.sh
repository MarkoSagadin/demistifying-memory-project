#!/usr/bin/env bash

filename="${1%.*}"

# freeze \
#     --font.family "MesloLGSDZ Nerd Font" \
#     --theme dracula \
#     --border.width 5 \
#     --border.color "#c4c4c4" \
#     --border.radius 8 \
#     --window -o ${filename}.png $1

freeze \
    --border.width 5 \
    --border.color "#c4c4c4" \
    --border.radius 8 \
    --window -o ${filename}.png $1
