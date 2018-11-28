CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

unittestresults: unitTest1.c unitTest2.c cardTest1.c dominion.o rngs.o
	echo "Result for running unitTest1 tests:" >> unittestresults.out
	echo "unitTest1.c:" >> unittestresults.out
	gcc -o unitTest1 dominion.o rngs.o unitTest1.c $(CFLAGS)
	./unitTest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "Result for running unitTest2 tests:" >> unittestresults.out
	echo "unitTest2.c:" >> unittestresults.out
	gcc -o unitTest2 dominion.o rngs.o unitTest2.c $(CFLAGS)
	./unitTest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "Result for running cardTest1 tests:" >> unittestresults.out
	echo "cardTest1.c:" >> unittestresults.out
	gcc -o cardTest1 dominion.o rngs.o cardTest1.c $(CFLAGS)
	./cardTest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

randomtestresults: randomtestadventurer.c randomtestcard1.c randomtestcard2.c dominion.o rngs.o
	echo "Result for running randomtestadventurer tests:" >> randomtestadventurer.out
	echo "randomtestadventurer.c:" >> randomtestadventurer.out
	gcc -o randomtestadventurer dominion.o rngs.o randomtestadventurer.c $(CFLAGS)
	./randomtestadventurer >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out

	echo "Result for running randomtestcard1 tests:" >> randomtestcard1.out
	echo "randomtestcard1.c:" >> randomtestcard1.out
	gcc -o randomtestcard1 dominion.o rngs.o randomtestcard1.c $(CFLAGS)
	./randomtestcard1 >> randomtestcard1.out
	gcov dominion.c >> randomtestcard1.out

	echo "Result for running randomtestcard2 tests:" >> randomtestcard2.out
	echo "randomtestcard2.c:" >> randomtestcard2.out
	gcc -o randomtestcard2 dominion.o rngs.o randomtestcard2.c $(CFLAGS)
	./randomtestcard2 >> randomtestcard2.out
	gcov dominion.c >> randomtestcard2.out

randTestAdv: randomtestadventurer.c dominion.o rngs.o
	gcc -o randTestAdv randomtestadventurer.c dominion.o rngs.o $(CFLAGS)

randTest1: randomtestcard1.c dominion.o rngs.o
	gcc -o randTest1 randomtestcard1.c dominion.o rngs.o $(CFLAGS)

randTest2: randomtestcard2.c dominion.o rngs.o
	gcc -o randTest2 randomtestcard2.c dominion.o rngs.o $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
