#!/bin/bash

i=1

BRed='\033[1;31m'
BGreen='\033[1;32m'
NC='\033[0m' # No color

clear
echo -e "\033[0;30m			░▒▓████████▓▒░▒▓████████▓▒░░▒▓███████▓▒░▒▓████████▓▒░▒▓████████▓▒░▒▓███████▓▒░        ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓███████▓▒░▒▓███████▓▒░░▒▓███████▓▒░  
			   ░▒▓█▓▒░   ░▒▓█▓▒░      ░▒▓█▓▒░         ░▒▓█▓▒░   ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░     ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ 
			   ░▒▓█▓▒░   ░▒▓█▓▒░      ░▒▓█▓▒░         ░▒▓█▓▒░   ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░     ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ 
			   ░▒▓█▓▒░   ░▒▓██████▓▒░  ░▒▓██████▓▒░   ░▒▓█▓▒░   ░▒▓██████▓▒░ ░▒▓███████▓▒░       ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓███████▓▒░▒▓███████▓▒░░▒▓█▓▒░░▒▓█▓▒░ 
			   ░▒▓█▓▒░   ░▒▓█▓▒░             ░▒▓█▓▒░  ░▒▓█▓▒░   ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░     ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ 
			   ░▒▓█▓▒░   ░▒▓█▓▒░             ░▒▓█▓▒░  ░▒▓█▓▒░   ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░     ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ 
			   ░▒▓█▓▒░   ░▒▓████████▓▒░▒▓███████▓▒░   ░▒▓█▓▒░   ░▒▓████████▓▒░▒▓█▓▒░░▒▓█▓▒░       ░▒▓██████▓▒░ ░▒▓██████▓▒░░▒▓███████▓▒░▒▓███████▓▒░░▒▓███████▓▒░  
	                                                                                                                                               \033[0m"

if [[ $1 -eq 0 ]];
then
	cd ..
	echo "Test argument :"
elif [[ $1 -eq 1 ]]; then
	cd ..
	echo -e "\n\033[1;38m▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
	
	██████   █████  ████████  █████      ██████   █████  ██████  ███████ ██ ███    ██  ██████  
	██   ██ ██   ██    ██    ██   ██     ██   ██ ██   ██ ██   ██ ██      ██ ████   ██ ██       
	██   ██ ███████    ██    ███████     ██████  ███████ ██████  ███████ ██ ██ ██  ██ ██   ███ 
	██   ██ ██   ██    ██    ██   ██     ██      ██   ██ ██   ██      ██ ██ ██  ██ ██ ██    ██ 
	██████  ██   ██    ██    ██   ██     ██      ██   ██ ██   ██ ███████ ██ ██   ████  ██████ 
                                                                                     
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\033[0m\n"
	for i in {1..10}
	do
		if (( $i <= -1 )); then
			valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./cub3d maps/parsing_data_ok/test_data_parsing"$i".cub > tester_cub3d/test$i.ok 2> tester_cub3d/test"$i".err
		elif (( $i <= 10 )); then
			valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./cub3d maps/parsing_data_failure/test_data_parsing"$i".cub > tester_cub3d/test$i.ok 2> tester_cub3d/test"$i".err
		(( i += 1 ))
		fi
	done
	(( i = 0 ))
	cd tester_cub3d
	for i in {1..10}
	do
		if (( $i <= -1 )); then
			answer=$(cat test$i.ok | wc -l)
			if [[ $answer -eq 3 ]]; then
				echo -n "TEST$i: "
				echo -e $BGreen"OK   ✅"$NC
			else
				echo -n "TEST$i: "
				echo -e -n $BRed"KO   ❌"$NC
				echo -e $BRed"		maps/parsing_data_failure/test_data_parsing"$i".cub"$NC
			fi
		elif (( $i <= 10 )); then
			answer=$(cat test$i.ok | wc -l)
			wrong=$(cat test$i.err | wc -l)
			if (( $i == 6 || $i == 7 )); then
				if [[ $answer -eq 1 && $wrong -eq 19 ]]; then
					echo -n "TEST$i: "
					echo -e $BGreen"OK   ✅"$NC
				else
					echo -n "TEST$i: "
					if (( $wrong > 18 )); then
						echo -e -n $BRed"KO   ❌"$NC
						echo -e -n $BRed"	LEAK/FD"
						echo -e $BRed"		maps/parsing_data_failure/test_data_parsing"$i".cub"$NC
					else
						echo -e -n $BRed"KO   ❌"$NC
						echo -e $BRed"		maps/parsing_data_failure/test_data_parsing"$i".cub"$NC
					fi
				fi
			elif (( $i == 8 || $i == 9 || $i == 10 )); then
				if [[ $answer -eq 0 && $wrong -eq 18 ]]; then
					echo -n "TEST$i: "
					echo -e $BGreen"OK   ✅"$NC
				else
					echo -n "TEST$i: "
					if (( $wrong > 18 )); then
						echo -e -n $BRed"KO   ❌"$NC
						echo -e -n $BRed"	LEAK/FD"
						echo -e $BRed"		maps/parsing_data_failure/test_data_parsing"$i".cub"$NC
					else
						echo -e -n $BRed"KO   ❌"$NC
						echo -e $BRed"		maps/parsing_data_failure/test_data_parsing"$i".cub"$NC
						fi
				fi
			else
				if [[ $answer -eq 1 && $wrong -eq 18 ]]; then
					echo -n "TEST$i: "
					echo -e $BGreen"OK   ✅"$NC
				else
					echo -n "TEST$i: "
					if (( $wrong > 18 )); then
						echo -e -n $BRed"KO   ❌"$NC
						echo -e -n $BRed"	LEAK/FD"$NC
						echo -e $BRed"		maps/parsing_data_failure/test_data_parsing"$i".cub"$NC
					else
						echo -e -n $BRed"KO   ❌"$NC
						echo -e $BRed"		maps/parsing_data_failure/test_data_parsing"$i".cub"$NC
					fi
				fi
			fi
		fi
		(( i += 1 ))
	done
elif [[ $1 -eq 2 ]]; then
	cd ..
	echo -e "\n\033[1;38m▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
	
	███    ███  █████  ██████      ██████   █████  ██████  ███████ ██ ███    ██  ██████  
	████  ████ ██   ██ ██   ██     ██   ██ ██   ██ ██   ██ ██      ██ ████   ██ ██       
	██ ████ ██ ███████ ██████      ██████  ███████ ██████  ███████ ██ ██ ██  ██ ██   ███ 
	██  ██  ██ ██   ██ ██          ██      ██   ██ ██   ██      ██ ██ ██  ██ ██ ██    ██ 
	██      ██ ██   ██ ██          ██      ██   ██ ██   ██ ███████ ██ ██   ████  ██████  
                                                                                     
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\033[0m\n"
	for i in {1..10}
	do
		if (( $i <= 5 )); then
			valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./cub3d maps/parsing_map_ok/test_map_parsing"$i".cub > tester_cub3d/test$i.ok 2> tester_cub3d/test"$i".err
		else
			valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./cub3d maps/parsing_map_failure/test_map_parsing"$i".cub > tester_cub3d/test$i.ok 2> tester_cub3d/test"$i".err
		fi
		(( i += 1 ))
	done
	(( i = 0 ))
	cd tester_cub3d
	for i in {1..10}
	do
		if (( $i <= 5 )); then
			answer=$(cat test$i.ok | wc -l)
			if [[ $answer -eq 3 ]]; then
				echo -n "TEST$i: "
				echo -e $BGreen"OK   ✅"$NC
			else
				echo -n "TEST$i: "
				echo -e -n $BRed"KO   ❌"$NC
				echo -e $BRed"		maps/parsing_map_ok/test_map_parsing"$i".cub"$NC
			fi
		elif (( $i <= 10 )); then
			answer=$(cat test$i.ok | wc -l)
			wrong=$(cat test$i.err | wc -l)
			if [[ $answer -eq 0 && $wrong -eq 18 ]]; then
				echo -n "TEST$i: "
				echo -e $BGreen"OK   ✅"$NC
			else
				echo -n "TEST$i: "
				if (( $wrong > 18 )); then
					echo -e -n $BRed"KO   ❌"$NC
					echo -e -n $BRed"	LEAK/FD"$NC
					echo -e $BRed"		maps/parsing_map_failure/test_map_parsing"$i".cub"$NC
				else
					echo -e -n $BRed"KO   ❌"$NC
					echo -e $BRed"		maps/parsing_map_failure/test_map_parsing"$i".cub"$NC
				fi
			fi
		fi
		(( i += 1 ))
	done
elif [[ $1 -eq 3 ]]; then
	cd ..
	echo "Test game :"
elif [[ $1 -eq 4 ]]; then
	echo "Test all the game."
elif [[ $1 -eq 5 ]]; then
	echo -e $BGreen"	HELP MENU\n"$NC
	echo -e $BGreen"0 - Parse the argument."$NC
	echo -e $BGreen"1 - Parse the data."$NC
	echo -e $BGreen"2 - Parse the map."$NC
	echo -e $BGreen"3 - Parse the game."$NC
	echo -e $BGreen"4 - Parse all the game."$NC
	echo -e $BGreen"5 - Help."$NC
	echo -e $BGreen"6 and upper - remove the testing files.\n"$NC
else
	rm *.err *.ok
	echo -e $BGreen"Remove file done !"$NC
fi

