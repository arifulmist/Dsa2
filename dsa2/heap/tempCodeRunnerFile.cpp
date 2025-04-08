int count = 0;
    while (!h.empty())
    {
        int mod = (202314129 % 9);
        count++;
        if (count == mod + 1)
        {
            int idx = h.find();
            h.delete_at(idx);
            count = 0;
        }
        custom c = h.Top();
        cout << "Customer: " << c.name << " Amount: " << c.amount << " Timestamp: " << c.timestamp << endl;
        h.Pop();
    }