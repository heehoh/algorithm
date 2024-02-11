import java.util.*;
import java.io.*;

public class Main {
    static int[] parent;
    static boolean[] truePeople = new boolean[51];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);
        
        parent = new int[N+1];
        for (int i = 1; i<=N; ++i) {
            parent[i] = i;
        }
        input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        for (int i = 1; i<=n; ++i) {
            truePeople[Integer.parseInt(input[i])] = true;
        }
        
        ArrayList<Integer>[] peoples = new ArrayList[M];
		for(int i=0; i<M; i++) {
			peoples[i] = new ArrayList<>();
		}
        int val, pre = 0;
        for (int i=0; i<M; ++i) {
            input = br.readLine().split(" ");
            n = Integer.parseInt(input[0]);
            pre = Integer.parseInt(input[1]);
            peoples[i].add(pre);
            for (int j=1; j<n; ++j) {
                val = Integer.parseInt(input[j+1]);
                peoples[i].add(val);
                union(pre, val);
                pre = val;
            }
        }
        
        int parent;
        for(int i=1; i<truePeople.length; i++) {
			if(truePeople[i]) {
				truePeople[find(i)] = true;
			}
		}
        int total = 0;
        for(int i=0; i<M; i++) {
			if(peoples[i].size() > 0) {
				parent = find(peoples[i].get(0));
				if(!truePeople[parent]) total++;
			}
		}
        System.out.println(total);
    }
    
    static int find(int x) {
		if(parent[x] == x) 
			return x;
		return find(parent[x]);
	}
	
	static void union(int a, int b) {
		a = find(a);
		b = find(b);
		
		if(a!= b) {
			if(a>b) {
				parent[a] = b;
			} else {
				parent[b] = a;
			}
		}
	}
}