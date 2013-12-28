double variables[256];

void var_set(char var_name, double value) {
  variables[var_name] = value;
}

double var_get(char var_name) {
  return variables[var_name];
}
