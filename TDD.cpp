#include <bits/stdc++.h>
using namespace std;

class Chandrayaan3
{
public:
    Chandrayaan3()
    {
        position = {0, 0, 0}; // Initial position (x, y, z)
        direction = 'N';      // Initial direction (N, S, E, W, U, D)
        prev = 'N';
    }

    void move(char command, char dir)
    {
        if (command == 'f')
        { // moving forward in current direction
            if (dir == 'N')
                position[1]++;
            else if (dir == 'S')
                position[1]--;
            else if (dir == 'E')
                position[0]++;
            else if (dir == 'W')
                position[0]--;
            else if (dir == 'U')
                position[2]++;
            else if (dir == 'D')
                position[2]--;
        }
        else if (command == 'b')
        { // moving backwords in current direction
            if (dir == 'N')
                position[1]--;
            else if (dir == 'S')
                position[1]++;
            else if (dir == 'E')
                position[0]--;
            else if (dir == 'W')
                position[0]++;
            else if (dir == 'U')
                position[2]--;
            else if (dir == 'D')
                position[2]++;
        }
    }

    void turn(char command, char dir)
    {
        if (command == 'l')
        { // rotating to left by 90 degree
            if (dir == 'N')
                direction = 'W';
            else if (dir == 'S')
                direction = 'E';
            else if (dir == 'E')
                direction = 'N';
            else if (dir == 'W')
                direction = 'S';
            else if (dir == 'U') // if current direction is up or down we use previous direction
            {
                turn(command, prev); // calling function with previous direction values
            }
            else if (dir == 'D')
            {
                turn(command, prev);
            }
        }
        else if (command == 'r')
        { // rotating to left by 90 degree
            if (dir == 'N')
                direction = 'E';
            else if (dir == 'S')
                direction = 'W';
            else if (dir == 'E')
                direction = 'S';
            else if (dir == 'W')
                direction = 'N';
            else if (dir == 'U') // if current direction is up or down we use previous direction
            {
                turn(command, prev);
            }
            else if (dir == 'D')
            {
                turn(command, prev);
            }
        }
    }

    void tilt(char command, char dir)
    {
        if (command == 'u')
        {
            if (dir == 'N')
                prev = 'N', direction = 'U'; // for next time when we use turn we need previous direction
            else if (dir == 'S')
                prev = 'S', direction = 'U';
            else if (dir == 'E')
                prev = 'E', direction = 'U';
            else if (dir == 'W')
                prev = 'W', direction = 'U';
            else
                direction = 'U';
        }
        else if (command == 'd')
        {
            if (dir == 'N')
                prev = 'N', direction = 'D';
            else if (dir == 'S')
                prev = 'S', direction = 'D';
            else if (dir == 'E')
                prev = 'E', direction = 'D';
            else if (dir == 'W')
                prev = 'W', direction = 'D';

            else
                direction = 'D';
        }
    }

    void executeCommands(const std::vector<char> &commands)
    {
        for (char command : commands)
        {
            if (command == 'f' || command == 'b')
            {
                move(command, direction);
            }
            else if (command == 'l' || command == 'r')
            {
                turn(command, direction);
            }
            else if (command == 'u' || command == 'd')
            {
                tilt(command, direction);
            }
        }
    }

    void printPosition() const
    {
        cout << "Final Position: (" << position[0] << ", " << position[1] << ", " << position[2] << ")\n";
    }

    void printDirection() const
    {
        cout << "Final Direction: " << direction << "\n";
    }

private:
    vector<int> position;
    char direction;
    char prev;
};

int main()
{
    Chandrayaan3 Rover;
    vector<char> commands = {'f', 'r', 'u', 'b', 'l'};

    Rover.executeCommands(commands);

    Rover.printPosition();
    Rover.printDirection();

    return 0;
}