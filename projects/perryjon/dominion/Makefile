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

unit1:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o unittest1.c unittestHelper.c unittestHelper.h rngs.o -o unittest1 -lm -g
unit2:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o unittest2.c unittestHelper.c unittestHelper.h rngs.o -o unittest2 -lm -g
unit3: 
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o unittest3.c unittestHelper.c unittestHelper.h rngs.o -o unittest3 -lm -g
unit4: 
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o unittest4.c unittestHelper.c unittestHelper.h rngs.o -o unittest4 -lm -g

card1: 
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o cardtest1.c unittestHelper.c unittestHelper.h rngs.o -o cardtest1 -lm -g
card2: 
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o cardtest2.c unittestHelper.c unittestHelper.h rngs.o -o cardtest2 -lm -g
card3: 
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o cardtest3.c unittestHelper.c unittestHelper.h rngs.o -o cardtest3 -lm -g
card4:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o cardtest4.c unittestHelper.c unittestHelper.h rngs.o -o cardtest4 -lm -g

randomtestadventurer:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o randomtestadventurer.c unittestHelper.c unittestHelper.h rngs.o -o randomtestadventurer -lm -g

unittestresults:
	./unittest1 &> unittestresult.out
	gcov unittest1.c >> unittestresult.out
	cat unittest1.c.gcov >> unittestresult.out

	./unittest2 >> unittestresult.out
	gcov unittest2.c >> unittestresult.out
	cat unittest2.c.gcov >> unittestresult.out

	./unittest3 >> unittestresult.out
	gcov unittest3.c >> unittestresult.out
	cat unittest3.c.gcov >> unittestresult.out

	./unittest4 >> unittestresult.out
	gcov unittest4.c >> unittestresult.out
	cat unittest4.c.gcov >> unittestresult.out

	./cardtest1 >> unittestresult.out
	gcov cardtest1.c >> unittestresult.out
	cat cardtest1.c.gcov >> unittestresult.out

	./cardtest2 >> unittestresult.out
	gcov cardtest2.c >> unittestresult.out
	cat cardtest2.c.gcov >> unittestresult.out

	./cardtest3 >> unittestresult.out
	gcov cardtest3.c >> unittestresult.out
	cat cardtest3.c.gcov >> unittestresult.out

	./cardtest4 >> unittestresult.out
	gcov cardtest4.c >> unittestresult.out
	cat cardtest4.c.gcov >> unittestresult.out
	
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player unit1 unit2 unit3 unit4 card1 card2 card3 card4 randomtestadventurer

clean:
	rm -f *.o playdom.exe playdom player player.exe unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestadventurer *.gcov *.gcda *.gcno *.so *.out *.exe testDrawCard testDrawCard.exe
