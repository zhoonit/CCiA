template <typename Predicate>
void minimal_wait(std::unique_lock<std::mustex> &lk, Predicate pred) {
    while(!pred()) {
        lk.unlock();
        lk.lock();
    }
}