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

randomtestadventurer:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o randomtestadventurer.c unittestHelper.c unittestHelper.h rngs.o -o randomtestadventurer -lm -g

randomtestcard1:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o randomtestcard1.c unittestHelper.c unittestHelper.h rngs.o -o randomtestcard1 -lm -g

randomtestcard2:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o randomtestcard2.c unittestHelper.c unittestHelper.h rngs.o -o randomtestcard2 -lm -g

unittestresults:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o unittest1.c unittestHelper.c unittestHelper.h rngs.o -o unittest1 -lm -g
	./unittest1 &> unittestresult.out
	gcov -f -b unittest1.c >> unittestresult.out
	cat unittest1.c.gcov >> unittestresult.out

	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o unittest2.c unittestHelper.c unittestHelper.h rngs.o -o unittest2 -lm -g
	./unittest2 >> unittestresult.out
	gcov -f -b unittest2.c >> unittestresult.out
	cat unittest2.c.gcov >> unittestresult.out

	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o unittest3.c unittestHelper.c unittestHelper.h rngs.o -o unittest3 -lm -g
	./unittest3 >> unittestresult.out
	gcov -f -b unittest3.c >> unittestresult.out
	cat unittest3.c.gcov >> unittestresult.out

	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o unittest4.c unittestHelper.c unittestHelper.h rngs.o -o unittest4 -lm -g
	./unittest4 >> unittestresult.out
	gcov -f -b unittest4.c >> unittestresult.out
	cat unittest4.c.gcov >> unittestresult.out

	
	gcov -f -b dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

randomtestresults:
	./randomtestadventurer &> randomtestadventurer.out
	gcov -f -b dominion.c >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

	./randomtestcard1 &> randomtestcard1.out
	gcov -f -b dominion.c >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out

	./randomtestcard2 &> randomtestcard2.out
	gcov -f -b dominion.c >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out



player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player randomtestadventurer randomtestcard1 randomtestcard2 randomtestresults unittestresults

clean:
	rm -f *.o playdom.exe playdom player player.exe unittest1 unittest2 unittest3 unittest4 randomtestadventurer randomtestcard1 randomtestcard2 randomtestresults *.gcov *.gcda *.gcno *.so *.out *.exe testDrawCard testDrawCard.exe
