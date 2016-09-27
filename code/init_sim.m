function sim = init_sim(max_sec, T)

sim.flag = 1;  
sim.T = T; 
sim.tick = 0;

sim.sec = sim.tick*sim.T;
sim.max_sec = max_sec;
sim.pause = 0;
