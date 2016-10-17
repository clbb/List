list:list.cpp
	g++ -o $@ $^ 
.PHONY:clean
clean:
	rm -rf list
