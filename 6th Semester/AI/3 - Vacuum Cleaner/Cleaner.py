from time import sleep


def simple_vacuum_cleaner_agent(percept):
    position, status = percept
    if status == 'DIRTY':
        return 'SUCK'
    elif position == 'A':
        return 'RIGHT'
    elif position == 'B':
        return 'LEFT'


def check_clean(state):
    for key in state:
        if state[key] == 'DIRTY':
            return False
    return True


if __name__ == "__main__":
    state = {'A': 'DIRTY', 'B': 'DIRTY'}
    current_position = 'A'
    current_status = state[current_position]
    while True:
        print('State:', state)
        print('Vacuum Cleaner Location:', current_position)
        percept = [current_position, current_status]
        action = simple_vacuum_cleaner_agent(percept)
        sleep(1)
        print('Action:', action)
        if action == 'SUCK':
            state[current_position] = 'CLEAN'
        elif action == 'RIGHT':
            current_position = 'B'
        elif action == 'LEFT':
            current_position = 'A'
        current_status = state[current_position]
        print()
        if check_clean(state):
            print(state)
            break
