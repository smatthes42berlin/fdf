# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 09:38:54 by smatthes          #+#    #+#              #
#    Updated: 2023/10/27 16:46:48 by smatthes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

path_maps=./example_program_from_subject/maps/

files=$(ls $path_maps)

# mapname="pyra.fdf"
# ./fdf "${path_maps}${mapname}"
# ./example_program_from_subject/fdf_linux "${path_maps}${mapname}"

# mapname="pentenegpos.fdf"
# ./fdf "${path_maps}${mapname}"
# ./example_program_from_subject/fdf_linux "${path_maps}${mapname}"


# exit

for map in $files; do
    echo $map
    ./fdf $path_maps$map
done
