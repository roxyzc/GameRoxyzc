#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#define label_balikLagi LL

using namespace std;

void delay(void){
    int delay = 1;
    while(delay < 10000000){
        delay++;
    }
}
void gotoxy(int x, int y){
    COORD coord;//coord itu kordinat
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

class Equipment{
public:
    int coin;
    int damageBuff;
    int buffDefense;
    int sisaBarang;
    int sisaSenjata;

    Equipment(int coin1){
    Equipment::coin = coin1;
    Equipment::damageBuff = 0;
    Equipment::buffDefense = 0;
    Equipment::sisaBarang = 1;
    Equipment::sisaSenjata = 1;
    }

    int buy(int coinPlayer, int dmg){
        label_balikLagi:
        cout << "-Shop-\n";
        cout << "1. Pedang\n";
        cout << "2. Panah\n";
        cout << "3. Defense\n";
        cout << "4. EXIT\n";
        int pilihBarang;
        int pilih_lagi;
        char larangan;
        cout << "PILIH : ";
        cin >> pilihBarang;
        system("cls");
            if(pilihBarang == 1){
                cout << "1. ENMA (5000 Coin & damage 10000)" << endl;
                cout << "2. Roxyzc (10000 Coin & damage 20000)" << endl;
                cout << "3. Kembali" <<endl;
                cout << "PILIH : ";
                cin >> pilih_lagi;
                system("cls");
                if(pilih_lagi == 1 && coinPlayer >= 5000){
                    if(sisaSenjata <= 0){
                        goto LL;
                    }else{
                    Equipment::coin = 5000;
                    Equipment::damageBuff = 10000;
                    Equipment::buffDefense = 0;
                    sisaSenjata -= 1;
                    cout << "-Dibeli-";
                    }
                } else if(pilih_lagi == 2 && coinPlayer >= 10000){
                    if(sisaBarang <= 0){
                        goto LL;
                    }else{
                    Equipment::coin = 10000;
                    Equipment::damageBuff = 20000;
                    Equipment::buffDefense = 0;
                    sisaSenjata -= 1;
                    cout << "-Dibeli-";
                    }
                } else if(pilih_lagi == 3){
                    Equipment::coin = 0;
                    Equipment::damageBuff = 0;
                    Equipment::buffDefense = 0;
                    goto LL;
                } else {
                    goto LL;
                }
                getch();
        } else if (pilihBarang == 2){
            cout << "1. Panah ELf (5000 coin & damage 10000)\n";
            cout << "2. Roxyzc (10000 coin & damage 20000)\n";
            cout << "3. Kembali\n";
            cout << "PILIH : ";
            cin >> pilih_lagi;
            system("cls");
            if(pilih_lagi == 1 && coinPlayer >= 5000){
                    if(sisaSenjata <= 0){
                        goto LL;
                    }else{
                    Equipment::coin = 5000;
                    Equipment::damageBuff = 10000;
                    Equipment::buffDefense = 0;
                    sisaSenjata -= 1;
                    cout<< "-Dibeli-";
                    }
            } else if(pilih_lagi == 2 && coinPlayer >=10000){
                    if(sisaBarang <= 0){
                        goto LL;
                    }else{
                    Equipment::coin = 10000;
                    Equipment::damageBuff = 20000;
                    Equipment::buffDefense = 0;
                    sisaSenjata -= 1;
                    cout << "-Dibeli-";
                    }
            } else if(pilih_lagi == 3){
                Equipment::coin = 0;
                Equipment::damageBuff =0;
                Equipment::buffDefense = 0;
                goto LL;
            } else {
                goto LL;
            }
            getch();
        }else if(pilihBarang == 3){
            cout << "1. Zirah(5000 Coin dan 10000 Health)\n";
            cout << "2. Roxyzc(10000 Coin dan 20000 Health)\n";
            cout << "3. Kembali\n";
            cout << "Pilih : ";
            cin >> pilih_lagi;
            system("cls");
            if(pilih_lagi == 1 && coinPlayer >= 5000){
                    if(sisaBarang <= 0){
                        goto LL;
                    }else{
                    Equipment::coin = 5000;
                    Equipment::buffDefense = 10000;
                    Equipment::damageBuff = 0;
                    sisaBarang -= 1;
                    cout<< "-Dibeli-";
                    }
            } else if(pilih_lagi == 2 && coinPlayer >=10000){
                    if(sisaBarang <= 0){
                        goto LL;
                    }else{
                    Equipment::coin = 10000;
                    Equipment::buffDefense = 20000;
                    Equipment::damageBuff = 0;
                    sisaBarang -= 1;
                    cout << "-Dibeli-";
                    }
            } else if(pilih_lagi == 3){
                Equipment::coin = 0;
                Equipment::buffDefense =0;
                Equipment::damageBuff = 0;
                goto LL;
            } else {
                goto LL;
            }
            getch();
        }else if(pilihBarang == 4){
            Equipment::coin = 0;
            Equipment::damageBuff = 0;
            Equipment::buffDefense = 0;
        } else if(pilihBarang == larangan){
            pilihBarang == 4;
        } else {
            goto LL;
        }
    }
};

class Monster;
class Player{
public:
    string namaPlayer1;
    int damage;
    int health;
    int level;
    int expPlayer;
    int batasExp;
    int mp;
    int coin;
    int damageMagic;

    Player(const char* namaPlayer){
        this->namaPlayer1 = namaPlayer;
        this->damage = 20;
        this->health = 100;
        this->level = 1;
        this->expPlayer = 0;
        this->batasExp = 100;
        this->mp = 100;
        this->coin = 10000;
    }
    void namaPemain(){
        string nama;
        cout << "Nickname :";
        getline(cin, nama);
        this->namaPlayer1 = nama;
    }
    void cekStatus(){
        cout << "Nama      : "<< this->namaPlayer1 <<endl;
        cout << "Level     : "<< this->level <<endl;
        cout << "Health    : "<< this->health <<endl;
        cout << "Damage    : "<< this->damage <<endl;
        cout << "Exp       : "<< this->expPlayer <<endl;
        cout << "Mp        : "<< this->mp <<endl;
        cout << "Coin      : "<< this->coin <<endl;
    }
    void levelUpPlayer(){
        if(expPlayer >= batasExp){
        this->damage *= 1.5;
        this->level += 1;
        this->health += 100 * level;
        this->expPlayer = 0;
        this->batasExp *=2;
        this->mp *= level;
        this->coin += 100;
        cout << "-LEVEL UP-"<<endl;
        }
    }
    void nerf(){
        this->level -= 1;
        this->damage += 20 * level;
        this->health = 100*level;
        this->expPlayer = 0;
        this->batasExp /= 2;
        this->mp = 100*level;
        }
    void skillPlayer(){
        int pilihSkill;
        cout << "1. api"<<endl;
        cout << "2. Ultimate"<<endl;
        cout << "Pilih skill : ";
        cin >> pilihSkill;
        system("cls");
        if(pilihSkill == 1){
            cout << "1. Explosion"<<endl;
            cout << "2. fireball"<<endl;
            int pilihSkill1;
            cout << "Pilih skill : ";
            cin >> pilihSkill1;
            system("cls");
            if(pilihSkill1 == 1 && this->mp >= 500){
                this->mp -= 500;
                this->damageMagic = 1000;
                this->damage = damageMagic;
            }else if(pilihSkill1 == 2 && this->mp >= 300){
                this->mp -= 300;
                this->damageMagic = 1000;
                this->damage = damageMagic;
            } else {
                this->mp -= 10;
                this->damageMagic = 20 * level;
                this->damage = damageMagic;
            }
        } else if(pilihSkill == 2 && this->mp >=100000){
            cout << "Menculik Loli dengan karung"<< endl;
            this->mp-=100000;
            this->damageMagic = 99999999;
            this->damage = damageMagic;
        } else {
            cout << "Basic attack"<<endl;
            this->mp -= 10;
            this->damageMagic = 10 * level;
            this->damage = damageMagic;
        }
    }
    friend bool curse(const Player& player1, const Monster& monster1);
    friend bool curse(const Monster& monster1, const Player& player1);
};

class Monster{
public:
    string namaMonster;
    int levelMonster;
    double damageMonster;
    double damageBoss;
    int healthMonster;
    int healthBoss;
    int exp;
    int coinM;

    Monster(const char* nama){
        this->namaMonster = nama;
        this->damageBoss = 0;
        this->damageMonster = 10;
        this->levelMonster = 1;
        this->healthMonster = 15;
        this->healthBoss = 0;
        this->exp = 25;
        this->coinM = 25;
    }
    void statusMonster(){
        cout << "Nama      : "<< this->namaMonster <<endl;
        cout << "Level     : "<< this->levelMonster <<endl;
        cout << "Health    : "<< this->healthMonster <<endl;
        cout << "Damage    : "<< this->damageMonster <<endl;
        }
    void levelUpM(){
        this->levelMonster += 1;
        this->damageMonster += 10*levelMonster/2;
        this->healthMonster = 15 * levelMonster;
        this->exp += 25*levelMonster/5;
        this->coinM += 5;

        if(this->levelMonster == 10){
            this->namaMonster = "DRAGON";
            this->damageMonster = 1500;
            this->healthMonster = 30000 * this->levelMonster;
            this->coinM = 5000;
            this->exp = 5000;
        } else{
            this->namaMonster = "Loli";
            this->damageMonster = 10*levelMonster;
            this->healthMonster = 15*levelMonster;
            this->exp = 25*levelMonster;
            this->coinM = 5*levelMonster;
        }
    }
//    void boss(){
//        this->namaMonster = "MECHA (BOSS)";
//        this->damageBoss = 100 * 35;
//        this->damageMonster = damageBoss;
//        this->healthBoss = 1500 * levelMonster;
//        this->healthMonster = healthBoss;
//        this->exp = 500;
//        this->coinM = 500;
//    }
//    void nerfBoss(){
//        this->damageMonster = 10*levelMonster/2;
//        this->healthMonster = 15*levelMonster;
//        this->exp = 25*levelMonster/5;
//        this->coinM = 5;
//    }
    friend bool curse(const Player& player1, const Monster& Monster1);
    friend bool curse(const Monster& Monster1, const Player& player1);
};

bool curse(const Player& player1, const Monster& monster1){
    cout<< player1.damage<<endl;
    return true;
}

bool curse(const Monster& monster1, const Player& player1){
    cout<<monster1.damageMonster<<endl;
    return true;
}

int main(){
    int i, j;

    for(i = 50; i<=70; i++){
        gotoxy(i, 12);
        cout << "-";
        gotoxy(i, 14);
        cout << "-";
        system("color 3F");
        delay();
    }
    for(i = 1; i <= 100; i++){
        gotoxy(50, 13);
        cout << "L O A D I N G "<<i << " %";
        delay();
    }
    for(i = 1; i <= 2; i++){
    gotoxy(50,15);
    system("pause");
    }
    system("cls");
    for(i = 1; i <= 115; i++){
        gotoxy(i, 1);
        cout << "*";//bingkai atas
        gotoxy(i,28);
        cout << "*";//bingkai bawah
        delay();
    }
    for(i = 1; i<=28; i++){
        gotoxy(1, i);
        cout << "*";//bingkai samping kiri
        gotoxy(115, i);
        cout << "*";//bingkai samping kanan
        delay();
    }

    for(i = 8; i < 30; i++){
        gotoxy(i, 10);
        cout << "*";
        gotoxy(i, 11);
        cout << "*";
        gotoxy(i, 19);
        cout << "*";
        gotoxy(i,20);
        cout << "*";
        delay();
    }
    for(i = 10; i<=20; i++){
        gotoxy(8, i);
        cout << "*";
        gotoxy(9, i);
        cout << "*";
        gotoxy(10,i);
        cout << "*";
        gotoxy(11,i);
        cout << "*";
        delay();
    }
    for(i = 32; i<=50; i++){
        gotoxy(i, 15);
        cout << "*";
        gotoxy(i, 16);
        cout << "*";
        gotoxy(i,14);
        cout << "*";
        delay();
    }
    for(i = 12; i <= 18; i++){
        gotoxy(40, i);
        cout << "*";
        gotoxy(41, i);
        cout << "*";
        gotoxy(43, i);
        cout<< "*";
        gotoxy(39, i);
        cout << "*";
        gotoxy(42, i);
        cout << "*";
        delay();
    }
    for(i = 52; i<=68; i++){
        gotoxy(i, 15);
        cout << "*";
        gotoxy(i, 16);
        cout << "*";
        gotoxy(i,14);
        cout << "*";
        delay();
    }
    for(i = 12; i <= 18; i++){
        gotoxy(60, i);
        cout << "*";
        gotoxy(62, i);
        cout << "*";
        gotoxy(61, i);
        cout<< "*";
        gotoxy(59, i);
        cout << "*";
        gotoxy(58, i);
        cout << "*";
        delay();
    }

    for(i = 1; i <=2; i++){
        gotoxy(50, 13);
        cout << "N";
        gotoxy(51, 13);
        cout << "I";
        gotoxy(52, 13);
        cout << "C";
        gotoxy(53, 13);
        cout << "K";
        gotoxy(54, 13);
        cout << "N";
        gotoxy(55, 13);
        cout << "A";
        gotoxy(56, 13);
        cout << "M";
        gotoxy(57, 13);
        cout << "E";
        delay();
    }
        system("cls");
        for(i = 1; i <=2; i++){
            gotoxy(50, 13);
        }
    Player player1 = Player("Player");
    Monster monster1 = Monster("Loli");
    Equipment duit1 = Equipment(0);
    player1.namaPemain();
    int pilih;
    char pilihan;

    cout << "Selamat datang di permainan, "+ player1.namaPlayer1 +"\n";
//    system("pause");
    label_kembali:
    label_monsterNaiklevel:
    system("cls");
    cout << "Monster\n";
    monster1.statusMonster();
    cout << "\nPlayer\n";
    player1.cekStatus();
    cout << "\n1. bertahan"<<endl;
    cout << "2. Basic attack"<<endl;
    cout << "3. Skill"<<endl;
    cout << "4. Shop"<<endl;
    cout << "Pilih no : ";
    cin >> pilih;
    cin.ignore(256, '\n');
    cout << endl;
    if(pilih==1){
        player1.health += 50* player1.level /5;
        player1.mp += 20 * player1.level;
        player1.cekStatus();
        cout << endl;
    } else if(pilih==2){
        cout << "Damage Player ";
        curse(player1, monster1);
        monster1.healthMonster -= player1.damage;
        monster1.statusMonster();
        if(monster1.healthMonster <= 0){
        cout << "Musuh Telah dikalahkan"<<endl;
        cout << "Musuh lain telah datang"<<endl;
        player1.expPlayer += monster1.exp;
        player1.coin += monster1.coinM;
        player1.levelUpPlayer();
        monster1.levelUpM();
        }
    } else if(pilih==3){
        int dataDamage;
        dataDamage = player1.damage;
        player1.skillPlayer();
        monster1.healthMonster-=player1.damage;
        cout << "Damage ";
        curse(player1,monster1);
        monster1.statusMonster();
        player1.damage = dataDamage;
        if(monster1.healthMonster <= 0){
        cout << "Musuh Telah dikalahkan"<<endl;
        cout << "Musuh lain telah datang"<<endl;
        player1.expPlayer += monster1.exp;
        player1.coin += monster1.coinM;
        player1.levelUpPlayer();
        monster1.levelUpM();
        }
    }else if(pilih==4){
        duit1.buy(player1.coin, player1.damage);
        player1.health += duit1.buffDefense;
        player1.coin -= duit1.coin;
        player1.damage += duit1.damageBuff;
    }else{

    }
//    if(monster1.levelMonster == 2){
//            monster1.boss();
//        }else{
//            monster1.nerfBoss();
//            monster1.namaMonster = "Loli";
//        }
//        monster1.healthBoss = 0;
    unsigned int ia;
    ia = rand()%2;
    if(ia == 1){
        cout << "\nMusuh bertahan"<<endl;
        monster1.healthMonster += 15*1.5/5;
        monster1.statusMonster();
    } else if(ia == 2){
        player1.health -= monster1.damageMonster;
        cout << "\nMusuh menyerang anda"<<endl;
        cout << "Damage yang diterima ";
        curse(monster1,player1);
        player1.cekStatus();
        if(player1.health <= 0){
            cout << "Game over"<<endl;
            player1.nerf();
        }
    } else {
        player1.health -= monster1.damageMonster;
        cout << "\nMusuh menyerang anda"<<endl;
        cout << "Damage yang diterima ";
        curse(monster1,player1);
        player1.cekStatus();
        if(player1.health <= 0){
            cout << "Game over"<<endl;
            player1.nerf();
            if(player1.level <= 0){
            return 0;
            }
        }
    }

    cout << "Pilih [Y/G] : ";
    cin >> pilihan;
    if(pilihan == 'y'| pilihan == 'Y'){
        goto label_kembali;
    } else if(pilihan == 'g'| pilihan == 'G'){

    } else{
        goto label_kembali;
    }
    cout << "Yah nobbbbbbbbbbbbbbb"<<endl;
    cin.get();
    return 0;
    }
