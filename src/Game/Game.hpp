#pragma once

#include "Regiment.hpp"

class Game {
    public:
        Game();
        Game(std::vector<Regiment *> regimentsBlue, std::vector<Regiment *> regimentsRed) : _regimentsBlue(regimentsBlue), _regimentsRed(regimentsRed) {static int id = 0; id++; _id = id;}
        ~Game();

        std::vector<Regiment *> _regimentsBlue = {};
        std::vector<Regiment *> _regimentsRed = {};

        int _nbPlayerBlue = 0;
        int _nbPlayerRed = 0;


        float _ratio = 0;
        const float ratioPlayerSplit = 0.7f;
        const float ratioNewRegimentSpeciality = 0.3f;
        void calculateRatio();
        void calculateRatioSplit();
        void calculateRatioNewRegimentSpeciality();
        int _diffSpecialityOld = 0;

        void AddRegimentBlue(Regiment *regiment) { _regimentsBlue.push_back(regiment); }
        void AddRegimentRed(Regiment *regiment) { _regimentsRed.push_back(regiment); }

        void giveSpeciality();
        uint numberOfSpeciality();
        bool invalidGame();

        void display();

        Regiment *getArtyBlue() { return blueSpe[0]; }
        Regiment *getSkirmBlue() { return blueSpe[1]; }
        Regiment *getCavalryBlue() { return blueSpe[2]; }

        Regiment *getArtyRed() { return redSpe[0]; }
        Regiment *getSkirmRed() { return redSpe[1]; }
        Regiment *getCavalryRed() { return redSpe[2]; }

    protected:
    private:
        int _id;
        Regiment *blueSpe[3] = {nullptr, nullptr, nullptr};
        Regiment *redSpe[3] = {nullptr, nullptr, nullptr};
        void giveArtillery();
        void giveSkirm();
        void giveCavalry();
};