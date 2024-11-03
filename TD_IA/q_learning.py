import random
import gym
import numpy as np
import matplotlib.pyplot as plt
import time

def update_q_table(Q, s, a, r, sprime, alpha, gamma):
    max_future_q = max(Q[sprime])
    Q[s][a] = Q[s][a] + alpha * (r + gamma * max_future_q - Q[s][a])
    return Q  

def epsilon_greedy(Q, s, epsilon):
    if random.uniform(0, 1) < epsilon:
        action = random.choice(range(len(Q[s])))
    else:
        action = np.argmax(Q[s])
    return action

if __name__ == "__main__":
    num_sessions = 1  # Nombre de séances d'entraînement
    n_epochs = 1000
    max_itr_per_epoch = 1000
    List_Q=[]

    all_rewards = []

    for session in range(num_sessions):
        env = gym.make("Taxi-v3")
        env.reset()
        Q = np.zeros([env.observation_space.n, env.action_space.n])

        # Paramètres 
        alpha = 0.9  
        gamma = 0.95  
        initial_epsilon = 1.0
        final_epsilon = 0.01
        decay_rate = 0.9995

        session_rewards = []

        for e in range(n_epochs):
            epsilon = max(final_epsilon, initial_epsilon * (decay_rate ** e))
            total_reward = 0
            S, _ = env.reset()

            for _ in range(max_itr_per_epoch):
                A = epsilon_greedy(Q, S, epsilon)
                Sprime, R, done, _, _ = env.step(A)
                total_reward += R
                Q = update_q_table(Q, S, A, R, Sprime, alpha, gamma)
                S = Sprime
                if done:
                    break

            session_rewards.append(total_reward)
            
        List_Q = List_Q+[Q]
        all_rewards.append(session_rewards)
        env.close()

        # Sélectionner les récompenses tous les ..
        rewards_every = session_rewards[::1]  # Prend un point tous les ..

        # Ajout des paramètres à la légende
        label = (f'Session {session + 1}: α={alpha:.2f}, γ={gamma:.2f}, '
                 f'ε_initial={initial_epsilon:.2f}'
                 f'decay_rate={decay_rate:.2f}')
        plt.plot(range(0, n_epochs, 1), rewards_every, label=label)

    # Afficher les détails sur le graphique
    plt.xlabel('Episodes')
    plt.ylabel('Rewards')
    plt.legend()
    plt.show()
    
    def play_agent(env, Q):
        state, _ = env.reset()
        done = False

        while not done:
            env.render()  
            action = np.argmax(Q[state]) 
            state, reward, done, _, _ = env.step(action)  
            time.sleep(0.1)  

        env.close() 
            
    for i in List_Q:
        print(f"Session {session + 1} - Agent in action:")
        env = gym.make("Taxi-v3", render_mode='human')  
        play_agent(env, List_Q[session])  
        env.close()


    print("Training finished.\n")


    env.close()
