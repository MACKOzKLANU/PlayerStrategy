# A simple command-line game using Strategy pattern


## Code Structure

The code consists of the following classes:

1. **Ability**: This is an abstract base class representing an ability that can be used by the player. It includes a name for the ability and a pure virtual function `UseAbility(Player* P)` that must be implemented by derived classes to define the specific effect of the ability.

2. **Player**: This class represents the player in the game. It has properties for HP and DMG, a vector to store abilities, and methods to manage these abilities. The `UseAbilities` method allows the player to choose and use an ability, modifying their HP and DMG accordingly.

3. **Heal**: Derived from the Ability class, this class represents an ability that increases the player's HP by 10.

4. **DoubleDMG**: Derived from the Ability class, this class represents an ability that doubles the player's DMG.

5. **Meditate**: Derived from the Ability class, this class represents an ability that increases the player's HP by 10 and DMG by 10. It also outputs a message.

6. **Reverse**: Derived from the Ability class, this class represents an ability that decreases the player's HP by 10 and DMG by 10.

7. **SwapStats**: Derived from the Ability class, this class represents an ability that swaps the player's HP and DMG.

8. **BloodThirsty**: Derived from the Ability class, this class represents an ability that decreases the player's HP by 10 and increases DMG by 10.



## Game Execution

When you run the program, you will see the following sequence of actions:

1. Display the player's initial HP and DMG.

2. Add six different abilities to the player: Heal, DoubleDMG, Meditate, Reverse, SwapStats, and BloodThirsty.

3. Allow the player to choose and use one of these abilities.

4. Display the modified HP and DMG of the player after using the chosen ability.

## Example Output

An example output may look like this:

```
Strategy
HP: 100
DMG: 20

Available Abilities:
1: Heal
2: Double
3: Meditate
4: Reverse
5: SwapStats
6: BloodThirsty
Choose an Ability (1-6): 3
ammm...
HP: 110
DMG: 30
```
