#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
    classes : Vehicle , Slot, Ticket, Lot
*/

class Vehicle
{
private:
    int size;
    int id;
    bool status;

public:
    Vehicle(int s, int id) : size(s), id(id), status(true) {}

    int getsize()
    {
        return size;
    }

    int getid()
    {
        return id;
    }

    bool getstatus()
    {
        return status;
    }
};

class Slot
{
private:
    int size;
    int id;
    string status; // enums can be used ?

public:
    Slot(int s, int id) : size(s), id(id), status("free") {}

    int getsize()
    {
        return size;
    }

    int getid()
    {
        return id;
    }

    string getstatus()
    {
        return status;
    }

    void setstatus(string s)
    {
        status = s;
    }
};

class Ticket
{
private:
    int vid;
    int sid;

public:
    Ticket(int v, int s) : vid(v), sid(s) {}

    void printticketinfo()
    {
        cout << "Ticket #: " << vid << " Spot #: " << sid << endl;
    }
};

class Lot
{
private:
    static const int levels = 3;
    static const int smallslots = 3;
    static const int medslots = 3;
    static const int largeslots = 3;

    vector<vector<Slot>> slots;
    map<int, Slot> occupiedslots;

public:
    Lot()
    {
        slots.resize(levels);
        for (int i = 0; i < levels; i++)
        {
            vector<Slot> level;

            for (int m = 0; m < smallslots; m++)
            {
                level.push_back(Slot(1, m));
            }
            for (int j = smallslots; j < (smallslots + medslots); j++)
            {
                level.push_back(Slot(2, j));
            }
            for (int k = (smallslots + medslots); k < (smallslots + medslots + largeslots); k++)
            {
                level.push_back(Slot(3, k));
            }
            slots[i] = level;
        }
    }

    void park(Vehicle v)
    {
        Slot &s = findslot(v);
        s.setstatus("occupied");
        Ticket t(v.getid(), s.getid());
        t.printticketinfo();
        occupiedslots[v.getid()] = s;
        cout << "Vehicle " << v.getid() << " is parked at " << s.getid() << " whose size is " << s.getsize() << endl;
    }

    Slot &findslot(Vehicle v)
    {
        int vsize = v.getsize();
        for (vector<Slot> &temp : slots)
        {
            for (Slot &s : temp)
            {
                if (vsize == s.getsize() && s.getstatus() == "free")
                {
                    return s;
                }
            }
        }
        throw runtime_error("No available slot.");
    }

    void unpark(Vehicle v)
    {
        Slot &s = occupiedslots[v.getid()];
        s.setstatus("free");
        occupiedslots.erase(v.getid());
    }

    void getparkedspot(Vehicle v)
    {
        Slot &t = occupiedslots[v.getid()];
        int tid = t.getid();
        cout << "Vehicle " << v.getid() << " is parked at " << tid << endl;
    }
};

int main()
{
    Lot lot1;
    // vehicle id is coming from manual input
    // We can also add
    Vehicle v1(1, 100);
    Vehicle v2(2, 101);
    Vehicle v3(3, 102);
    Vehicle v4(1, 103);
    Vehicle v5(1, 104);
    Vehicle v6(1, 105);

    lot1.park(v1);
    lot1.park(v2);
    lot1.park(v3);
    lot1.park(v4);
    lot1.unpark(v1);
    lot1.park(v5);

    return 0;
}
