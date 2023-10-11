#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Ability;
class Player;
class Heal;

class Ability
{
protected:
    string name;
public:
    void SetName(string name)
    {
        this->name = name;
    }
    string GetName()
    {
        return this->name;
    }
    virtual void UseAbility(Player* P) = 0;
};

class Player
{
private:
    int HP;
    int DMG;
    vector<Ability*> abilities;
public:
    Player()
    {
        this->HP = 100;
        this->DMG = 20;
    }
    void AddAbility(Ability* a)
    {
        abilities.push_back(a);
    }
    void UseAbilities()
    {
       cout << "Available Abilities:" << endl;
    for (int i = 0; i < abilities.size(); i++)
    {
        cout << i + 1 << ": " << abilities[i]->GetName() << endl;
    }

    int choice;
    cout << "Choose an Ability (1-" << abilities.size() << "): ";
    cin >> choice;

    
    switch(choice){
        case 1:
            abilities[0]->UseAbility(this);
            break;
        case 2:
            abilities[1]->UseAbility(this);
            break;
        case 3:
            abilities[2]->UseAbility(this);
            break;
        case 4:
            abilities[3]->UseAbility(this);
            break;
        case 5:
            abilities[4]->UseAbility(this);
            break;
        case 6:
            abilities[5]->UseAbility(this);
            break;
        
           
        }
        
    }
    
    void SetHP(int hp)
    {
        this->HP = hp;
    }
    void SetDMG(int dmg)
    {
        this->DMG = dmg;
    }
    int GetHP()
    {
        return this->HP;
    }
    int GetDMG()
    {
        return this->DMG;
    }
};

class Heal : public Ability
{
public:
    Heal(string name)
    {
        this->name = name;
    }
    void UseAbility(Player* P) override
    {
        P->SetHP(P->GetHP()+10);
    }
};
class DoubleDMG : public Ability
{
public:
    DoubleDMG(string name)
    {
        this->name = name;
    }
    void UseAbility(Player* P) override
    {
        P->SetDMG(P->GetDMG()*2);
    }
};
class Meditate : public Ability
{
public:
    Meditate(string name)
    {
        this->name = name;
    }
    void UseAbility(Player* P) override
    {
        P->SetHP(P->GetHP()+10);
        P->SetDMG(P->GetDMG()+10);
        cout <<"ammm..."<<endl;
    }
};
class Reverse : public Ability
{
public:
    Reverse(string name)
    {
        this->name = name;
    }
    void UseAbility(Player* P) override
    {
        P->SetHP(P->GetHP()-10);
        P->SetDMG(P->GetDMG()-10);
    }
};

class SwapStats : public Ability
{
public:
    SwapStats(string name)
    {
        this->name = name;
    }
    void UseAbility(Player* P) override
    {
        int hp = P->GetHP();
        int dmg = P->GetDMG();
        P->SetHP(dmg);
        P->SetDMG(hp);
    }
};

class BloodThirsty : public Ability
{
public:
    BloodThirsty(string name)
    {
        this->name = name;
    }
    void UseAbility(Player* P) override
    {
        P->SetHP(P->GetHP()-10);
        P->SetDMG(P->GetDMG()+10);
    }
};


int main()
{
    cout << "Strategy"<<endl;
    Player* P = new Player();
    cout <<"HP: "<< P->GetHP() << endl;
    cout <<"DMG: "<<  P->GetDMG() << endl;

    P->AddAbility(new Heal("Heal"));
    P->AddAbility(new DoubleDMG("Double"));
    P->AddAbility(new Meditate("Meditate"));
    P->AddAbility(new Reverse("Reverse"));
    P->AddAbility(new SwapStats("SwapStats"));
    P->AddAbility(new BloodThirsty("BloodThirsty"));


    P->UseAbilities();
    cout <<"HP: "<< P->GetHP() << endl;
    cout <<"DMG: "<<  P->GetDMG() << endl;
    return 0;
}
