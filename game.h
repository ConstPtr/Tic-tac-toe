class game
{
    private:
        constexpr static char space = '_';
        const static int size = 9;
        const static int comboNum = 8;
        const static int comboElem = 3;
        const int combinations[comboNum][comboElem] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
        char field[size];
        char player;
        char AI;
        char winner;
    public:
        game();
        void chooseSide();
        void makeMove();
        char check();
        void AIMove();
        void message();
        void show();
        char GetPlayerSide();
};