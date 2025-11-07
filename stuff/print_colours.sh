for i in {1..17}; do
	for j in {1..17}; do
		echo -en "\033[48;2;$((255-$i*15));$((255-$j*15));$(($j*15))m     \033[0m";
	done
	echo -en "\n";
done
