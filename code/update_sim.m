function sim = update_sim(sim)

sim.tick = sim.tick + 1;
sim.sec = sim.tick * sim.T;

if sim.sec > sim.max_sec
    sim.flag = 0;
end
