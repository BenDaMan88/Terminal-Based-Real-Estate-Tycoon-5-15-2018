compiler = g++
exe = Assignment_3_exe

$(exe): Apartment.o Business_Complex.o Event.o House.o Player.o Property.o Tenant.o main.o
	$(compiler) Apartment.o Business_Complex.o Event.o House.o Player.o Property.o Tenant.o main.o -o $(exe)
Apartment.o: Apartment.cpp Apartment.h
	$(compiler) Apartment.cpp -c
Business_Complex.o: Business_Complex.cpp Business_Complex.h
	$(compiler) Business_Complex.cpp -c
Event.o: Event.cpp Event.h
	$(compiler) Event.cpp -c
House.o: House.cpp House.h
	$(compiler) House.cpp -c
Player.o: Player.cpp Player.h
	$(compiler) Player.cpp -c
Property.o: Property.cpp Property.h
	$(compiler) Property.cpp -c
Tenant.o: Tenant.cpp Tenant.h
	$(compiler) Tenant.cpp -c
main.o: main.cpp
	$(compiler) main.cpp -c
clean:
	rm -f *.o *.out $(exe)
