import numpy as np


class WumpusQLearning():

    def __init__(
            self,
            environment_rows: int,
            environment_columns: int,
            start_point: tuple,
            pits: list,
            wumpus: tuple,
            gold: tuple,
            episodes: int,
            epsilon: float,
            discount_factor: float,
            learning_rate: float) -> None:

        self.env_rows = environment_rows
        self.env_columns = environment_columns
        self.start_point = start_point
        self.pits = pits
        self.wumpus = wumpus
        self.gold = gold
        self.episodes = episodes
        self.epsilon = epsilon
        self.discount_factor = discount_factor
        self.lr = learning_rate

    def initialization(self) -> None:
        self.rewards = np.full((self.env_rows, self.env_columns), -1)
        for pit in self.pits:
            self.rewards[pit] = -1000
        self.rewards[self.wumpus] = -1000
        self.rewards[self.gold] = 1000

        self.q_table = np.zeros((self.env_rows, self.env_columns, 4))
        self.actions = ['up', 'down', 'right', 'left']

    def is_terminal_state(self, row_index: int, col_index: int) -> bool:
        if self.rewards[row_index, col_index] == -1:
            return False
        else:
            return True

    def next_action(self, current_row_index: int, current_col_index: int, epsilon: float) -> int:
        rand = np.random.random()

        if rand < epsilon:
            return np.argmax(self.q_table[current_row_index, current_col_index])
        else:
            return np.random.randint(len(self.actions))

    def move(self, current_row_index: int, current_col_index: int, action_index: int) -> tuple:
        new_row_index = current_row_index
        new_col_index = current_col_index

        # moving to next state

        if self.actions[action_index] == 'up' and current_row_index > 0:
            new_row_index -= 1
        elif self.actions[action_index] == 'down' and current_row_index < self.env_rows-1:
            new_row_index += 1
        elif self.actions[action_index] == 'right' and current_col_index < self.env_columns-1:
            new_col_index += 1
        elif self.actions[action_index] == 'left' and current_col_index > 0:
            new_col_index -= 1

        # compute reward

        reward = self.rewards[new_row_index, new_col_index]

        return new_row_index, new_col_index, reward

    def update_q_table(self, current_row: int, current_col: int, action_index: int, reward: int, new_row: int, new_col: int) -> None:

        self.q_table[current_row, current_col, action_index] = self.q_table[current_row, current_col, action_index] * (1 - self.lr) \
            + self.lr * (reward + self.discount_factor *
                         np.max(self.q_table[new_row, new_col]))
        #self.q_table[current_row , current_col ,action_index] = reward + (self.discount_factor * np.max(self.q_table[new_row, new_col]))

    def training(self) -> None:

        for episode in range(self.episodes):

            current_row, current_col = self.start_point

            while not self.is_terminal_state(current_row, current_col):

                # choosing next  action
                action_index = self.next_action(
                    current_row, current_col, self.epsilon)

                # moving to next state and compute reward
                new_row, new_col, reward = self.move(
                    current_row, current_col, action_index)

                # update Q-table by computing temporal difference
                self.update_q_table(current_row, current_col,
                                    action_index, reward, new_row, new_col)

                current_row, current_col = new_row, new_col

    def get_path(self, start_point: tuple) -> list:
        start_row, start_col = start_point

        path = []

        if self.is_terminal_state(start_row, start_col):
            return path

        else:
            current_row, current_col = start_row, start_col
            path.append([current_row, current_col])

            while not self.is_terminal_state(current_row, current_col):

                action_index = self.next_action(current_row, current_col, 1)

                current_row, current_col, _ = self.move(
                    current_row, current_col, action_index)

                path.append([current_row, current_col])

        return path
