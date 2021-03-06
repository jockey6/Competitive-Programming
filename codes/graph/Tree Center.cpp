int n;          // nº de vértices (numerados de 1 a n)
int deg[maxn];  // grau do vértice
int lv[maxn];   // "profundidade" do vértice (distância até a folha mais distante)
vector<int> g[maxn];

// grafo deve ser uma árvore, pode ter um ou dois centros (depende do diâmetro)
ii center() {
  if (n <= 2) return {1, (n == 1 ? -1 : 2)};
  queue<int> q;
  for (int u = 1; u <= n; ++u) {
    deg[u] = (int)g[u].size();          // não vale a pena calcular antes!
    if (deg[u] == 1) {
      q.push(u);
      lv[u] = 1;
    }
  }
  int c1 = -1, c2 = -1;                 // candidatos a ser centro
  int m = 0;                            // vértice mais "profundo"
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) if (--deg[v] == 1) {
      q.push(v);
      lv[v] = lv[u] + 1;
      if (lv[v] > m) {
        m = lv[v];
        c1 = v;
        c2 = -1;
      } else if (lv[v] == m) {
        c2 = v;
      }
    }
  }
  return {c1, c2};
}
