#include"CandyStore.h"
#include"Board.h"

using namespace std;

int main()
{
    Candy c1;
    c1.name="Fizz";
    c1.description="boost stamina";
    c1.EffectType="Stamina";
    c1.EffectValue=10;
    c1.Type="Magical";
    c1.price = 10;

    Candy c2;
    c2.name="Butterscotch";
    c2.description="Protects";
    c2.EffectType="Other";
    c2.EffectValue=2;
    c2.Type="Immunity";
    c2.price = 20;

    Candy c3;
    c3.name="Comet";
    c3.description="Gummy Barrier";
    c3.EffectType="Turns";
    c3.EffectValue=-2;
    c3.Type="Gummy";
    c3.price = 20;

    Candy candies[3]={c1,c2,c3};

    Player p2("August", 100, 50, candies, 3);
    p2.printInventory();

    CandyStore A(candies);
    A.printCandies();
    A.addCandy(c3, 0);
    A.printCandies();
    A.removeCandy("Butterscotch");
    A.printCandies();


}