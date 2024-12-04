/* This is the main execution file */
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <sstream>

using namespace std;



int main() {
    PlayerQueue cr;
    PlayerRecord record;

    // player key, player name, player age, player position, player market value
    cr.statusPlayer(1, "Ronaldo", 39, "Striker" , 20000000);
    cr.statusPlayer(2, "Messi", 37, "Left Winger" , 15000000);
    cr.statusPlayer(3, "Mbappe", 27, "Striker" , 200000000);
    cr.statusPlayer(4, "Halaand", 24, "Striker" , 190000000);
    cr.statusPlayer(5, "Vini jr", 25, "Right Winger" , 210000000);
    cr.statusPlayer(6, "Rodrigo", 39, "Striker" , 140000000);
    cr.statusPlayer(7, "Wirtz", 21, "Striker" , 90000000);
    cr.statusPlayer(8, "Alvarez", 23, "Striker" , 50000000);
    cr.statusPlayer(9, "Rashford", 25, "Right Winger" , 70000000);
    cr.statusPlayer(10, "Foden", 26, "Left Winger" , 100000000);
    cr.statusPlayer(11, "Kane", 33, "Striker" , 90000000);
    cr.statusPlayer(12, "Lewondoski", 34, "Striker" , 60000000);
    cr.statusPlayer(13, "Yamal", 17, "Left Winger" , 200000000);
    cr.statusPlayer(14, "Endrick", 18, "Striker" , 75000000);
    cr.statusPlayer(15, "Son", 28, "Right Winger " , 20000000);

    //Add records
    record.addRecord({1, "Ronaldo", 39, "Striker" , 20000000});
    record.addRecord({2, "Messi", 37, "Left Winger" , 15000000});
    record.addRecord({3, "Mbappe", 27, "Striker" , 200000000});
    record.addRecord({4, "Halaand", 24, "Striker" , 190000000});
    record.addRecord({5, "Vini jr", 25, "Right Winger" , 210000000});
    record.addRecord({6, "Rodrigo", 39, "Striker" , 140000000});
    record.addRecord({7, "Wirtz", 21, "Striker" , 90000000});
    record.addRecord({8, "Alvarez", 23, "Striker" , 50000000});
    record.addRecord({9, "Rashford", 25, "Right Winger" , 70000000});
    record.addRecord({10, "Foden", 26, "Left Winger" , 100000000});
    record.addRecordr({11, "Kane", 33, "Striker" , 90000000});
    record.addRecord({12, "Lewondoski", 34, "Striker" , 60000000});
    record.addRecord({13, "Yamal", 17, "Left Winger" , 200000000});
    record.addRecord({14, "Endrick", 18, "Striker" , 75000000});
    record.addRecord({15, "Son", 28, "Right Winger " , 20000000});

    cr.displaySortedPlayers();

    return 0;
}

