#ifndef WANNABEPOKEMON_H
#define WANNABEPOKEMON_H
#include <stdlib.h>
#include <stdio.h>

typedef enum Type{
    Fire,
    Water,
    Grass,
    Stone,
    Air,
} Typing;

typedef struct Move{
    int damage;
    enum Type type;
} Move;

typedef enum PlayerType{
    User,
    Opponent
} PlayerType;

typedef struct PlayerStats{
    int health;
    int damage;
    int defense;
    int maxPoints;
    int maxMoves;
    Move * moves;
    Typing type;
} PlayerStats;

typedef struct UserPlayer{
    PlayerStats stats;
} UserPlayer;

typedef struct OpponentPlayer{
    PlayerStats stats;
} OpponentPlayer;

typedef union Player{
    enum PlayerType playerType;
    struct OpponentPlayer opponent;
    struct UserPlayer user;
} Player;

// ---- Function Declarations ----

Player createPlayer(PlayerStats stats, PlayerType playerType);
UserPlayer createUserPlayer(PlayerStats stats);
OpponentPlayer createOpponentPlayer(PlayerStats stats);

// ---- Function Definitions ----

Player createPlayer(PlayerStats stats, PlayerType playerType){
    Player player;
    player.playerType = playerType;
    switch (player.playerType){
        case User:
            player.user = createUserPlayer(stats);
            return player;
        
        case Opponent:
            player.opponent = createOpponentPlayer(stats);
            return player;

        default:
            return player;
    }
}

UserPlayer createUserPlayer(PlayerStats stats){
    UserPlayer user;
    user.stats = stats;
    return user;
}   

OpponentPlayer createOpponentPlayer(PlayerStats stats){
    OpponentPlayer opponent;
    opponent.stats = stats;
    return opponent;
}



#endif