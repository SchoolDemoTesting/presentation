
projectx:	project.cpp
	g++ -Wall -Wextra project.cpp -o projectx

submit:
	git add .
	git commit -m "project submit"
	git push --all origin

