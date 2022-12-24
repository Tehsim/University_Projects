from wumpus_agent import WumpusQLearning

ENVIRONMENT_ROWS = 4
ENVIRONMENT_COLUMNS = 4

START_PONIT = (0, 0)

PITS = [(0, 3), (2, 0)]

WUMPUS = (2, 3)

GOLD = (1, 3)

EPISODES = 500

EPSILON = 0.5

DISCOUNT_FACTOR = 0.9

LEARNING_RATE = 0.8


wumpus_agent = WumpusQLearning(ENVIRONMENT_ROWS, ENVIRONMENT_COLUMNS, START_PONIT, PITS, WUMPUS, GOLD,
                                 EPISODES, EPSILON, DISCOUNT_FACTOR, LEARNING_RATE)


wumpus_agent.initialization()

print(wumpus_agent.rewards)

wumpus_agent.training()

print('Training Finished!!!')

print("Path to hunt GOLD!!! : ")

print(*wumpus_agent.get_path(START_PONIT))
