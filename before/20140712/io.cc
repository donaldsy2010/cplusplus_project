iint a;
    if (cin.good()) {
            cout << "cin is good!" << endl;
        }
    while (cin >> a) {
            cout << a << endl;
        }
    if (cin.eof()) {
            cout << "eof!" << endl;
        }
    if (cin.fail()) {
            cout << "fail!" << endl;
        }
    std::string s;
        cin >> s;
            cout << s << endl;


