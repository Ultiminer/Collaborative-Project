OBJS= entry_point.o
SRC= ../src
EXT_SRC= ../ext_src
VERSION=c++11
SUBSYS=console
OPT= O1

compile: $(OBJS)
	g++ -Wall -Wextra -Werror -std=$(VERSION) -m$(SUBSYS) -o test_app.exe $(OBJS) 
	./test_app.exe

entry_point.o: $(SRC)/entry_point.cpp $(SRC)/*.h 
	g++ -$(OPT) -Wall -Wextra -Werror -c $(SRC)/entry_point.cpp -I $(EXT_SRC)