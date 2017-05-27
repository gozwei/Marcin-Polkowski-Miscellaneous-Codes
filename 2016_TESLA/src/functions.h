bool name_cmp(const var &a, const var &b);
int find_value(const std::vector <var> variables, std::string varname);
void solve_equations(std::vector <var> &variables);
void print_result(std::vector <var> &variables);
std::vector <var> read_input(char* fname);