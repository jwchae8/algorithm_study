#include <stdio.h>

int main() {
  long long int i, n, vertex=150, face=50, edge=100;
  long long int vertices[8], faces[6], edges[12];
  scanf("%d", &n);
  scanf("%d %d %d %d %d %d", faces, faces+1, faces+2, faces+3, faces+4, faces+5);
  vertices[0] = faces[0] + faces[1] + faces[2];
  vertices[1] = faces[0] + faces[1] + faces[3];
  vertices[2] = faces[0] + faces[3] + faces[4];
  vertices[3] = faces[0] + faces[2] + faces[4];
  vertices[4] = faces[5] + faces[1] + faces[2];
  vertices[5] = faces[5] + faces[1] + faces[3];
  vertices[6] = faces[5] + faces[3] + faces[4];
  vertices[7] = faces[5] + faces[2] + faces[4];
  edges[0] = faces[0] + faces[1];
  edges[1] = faces[0] + faces[2];
  edges[2] = faces[0] + faces[3];
  edges[3] = faces[0] + faces[4];
  edges[4] = faces[5] + faces[1];
  edges[5] = faces[5] + faces[2];
  edges[6] = faces[5] + faces[3];
  edges[7] = faces[5] + faces[4];
  edges[8] = faces[1] + faces[2];
  edges[9] = faces[1] + faces[3];
  edges[10] = faces[3] + faces[4];
  edges[11] = faces[2] + faces[4];
  for(i=0; i<6; i++) {
    if(faces[i] < face) {
      face = faces[i];
    }
  }
  for(i=0; i<8; i++) {
    if(vertices[i] < vertex) {
      vertex = vertices[i];
    }
  }
  for(i=0; i<12; i++) {
    if(edges[i] < edge) { 
      edge = edges[i];
    }
  }
  if(n==1) {
    int face_sum=0;
    for(i=0; i<6; i++) {
      face_sum+=faces[i];
      if(faces[i] > face) {
        face = faces[i];
      }
    }
    printf("%lld\n", face_sum - face);
  }
  else
    printf("%lld\n", face * (n-2) * (n-1) * 4 + face * (n-2) * (n-2) + edge * (n-1) * 4 + edge * (n-2) * 4 + vertex * 4);
  return 0;
}
