"""
SNAKE AND LADDER GAME SIMULATION
bikalpa (2019-01-10)
RULE:
A player will get spawned only if she gets 1 in the dice. 
After that, if the player gets the number n in the dice, she moves forward n boxes
If there is a ladder starting from the square the player is currently in, she is promoted to the square where the ladder ends
If there is a snake starting from the square the player is currently in, she is demoted to the square where the tail of snake lies.
"""

import itertools
import random
import time

# Snakes and ladders do basically the same thing, they take the player to some another box. I put them
# here together, so it would be easier to check later.

SNAKESANDLADDERS = {
    27: 7,
    35: 5,
    39: 3,
    50: 34,
    59: 46,
    66: 24,
    73: 12,
    76: 63,
    89: 67,
    97: 86,
    99: 26,
    2: 23,
    8: 29,
    22: 41,
    28: 77,
    30: 32,
    44: 58,
    54: 69,
    70: 90,
    80: 83,
    87: 93,
}


class Dice:

    # Since all the players will use the same dice to play, there need not be more than one instances of dice
    # So, it is better if Dice is made static.
    @staticmethod
    def roll():
        return random.randint(1, 6)


class Player:
    def __init__(self, name):
        self.name = name.capitalize()
        self.position = 0

        # Initially, the player is not born (meaning she will remain at position 0 till dice shows 1
        self.born = False

        # Store the last three consecutive moves, we will use this later to check if it equals [6,6,6]
        self.last_three_moves = [0, 0, 0]

    def has_won(self):
        # If position = 100, player has won
        return self.position == 100

    def update_position(self, dicevalue):

        # the following two lines will pop one element(zeroth index element) from the list,
        # and add the latest dicevalue to the list
        # so that the list will be updated
        self.last_three_moves.pop(0)
        self.last_three_moves.append(dicevalue)

        if self.last_three_moves == [6, 6, 6]:
            self.position = 0
            self.born = False
            return

        new_pos = self.position + dicevalue

        # if new position exceeds 100, don't update the current position
        # instead, return
        if new_pos >= 100:
            return
        else:
            self.position = new_pos

        # if the new position has a snake or ladder, update the position after snake or ladder
        while self.position in SNAKESANDLADDERS:
            self.position = SNAKESANDLADDERS[self.position]

    def print_position(self):
        print(self.name, "POSITION ==>", str(self.position))

    def play(self):
        dicevalue = Dice.roll()
        print(self.name + ": DICE SHOWS " + str(dicevalue))

        if dicevalue == 1:
            self.born = True

        if not self.born:
            print(self.name + ": player is not born yet")
        else:

            # The following is emulation of a do-while loop
            while True:
                self.update_position(dicevalue)
                self.print_position()
                # if dicevalue is not 6, her turn is finished
                if dicevalue != 6:
                    break
                # else roll the dice again
                else:
                    dicevalue = Dice.roll()


class Game:
    def __init__(self, players):
        self.players = itertools.cycle(players)
        self.num_players = len(players)

        # This list is created so that we can check if any players have won
        # For checking that, we have called next(..) function on the list
        # If we had used the next(..) function on the original players iterator list,
        # then it would alter the playing sequence and it is difficult to know which player's turn it is next
        # So, self.players is for the sole purpose of tracking next player
        # and self.mutable_players is kind of temporary list
        self.mutable_players = itertools.cycle(players)

    def has_finished(self):
        # if anyone of the player has won, the game is finished
        for i in range(self.num_players):
            player = next(self.mutable_players)
            if player.has_won():
                return True
        return False

    def next_player(self):
        return next(self.players)


if __name__ == "__main__":
    no_of_players = int(input("Enter the no of player:"))
    player_names = [name for name in input(
        "Enter the name of players:").split()]
    players = [Player(name) for name in player_names]

    game = Game(players)

    while not game.has_finished():
        player = game.next_player()
        player.play()
        time.sleep(5)
