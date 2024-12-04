/* This is the main execution file */
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <PlayerRecord.h>


int main() {
    PlayerRecord record;
    

    //Add records
    std::cout << record.addRecord(1, "Ronaldo", 39, "Striker" , 20000000) << std::endl;
    std::cout << record.addRecord(2, "Messi", 37, "Left Winger" , 15000000) << std::endl;
    std::cout << record.addRecord(3, "Mbappe", 27, "Striker" , 200000000) << std::endl;
    std::cout << record.addRecord(4, "Halaand", 24, "Striker" , 190000000) << std::endl;
    std::cout << record.addRecord(5, "Vini jr", 25, "Right Winger" , 210000000) << std::endl;
    std::cout << record.addRecord(6, "Rodrigo", 39, "Striker" , 140000000)<< std::endl;
    std::cout << record.addRecord(7, "Wirtz", 21, "Striker" , 90000000)<< std::endl;
    std::cout << record.addRecord(8, "Alvarez", 23, "Striker" , 50000000)<< std::endl;
    std::cout << record.addRecord(9, "Rashford", 25, "Right Winger" , 70000000)<< std::endl;
    std::cout << record.addRecord(10, "Foden", 26, "Left Winger" , 100000000)<< std::endl;
    std::cout << record.addRecord(11, "Kane", 33, "Striker" , 90000000)<< std::endl;
    std::cout << record.addRecord(12, "Lewondoski", 34, "Striker" , 60000000)<< std::endl;
    std::cout << record.addRecord(13, "Yamal", 17, "Left Winger" , 200000000)<< std::endl;
    std::cout << record.addRecord(14, "Endrick", 18, "Striker" , 75000000)<< std::endl;
    std::cout << record.addRecord(15, "Son", 28, "Right Winger " , 20000000)<< std::endl;

    //record.displaySortedPlayers();

    return 0;
}

