/*
Write a program to find top 5 students list of all 3 subjects. 
From the lists print the students info who are present in all lists. 

Note : output rollnos in ascending order.


sample output : [14BD1A040F, 14BD1A0414]

*/
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.FutureTask;


class Student implements Comparable<Student> {
    String id;
    int marks;
    
    Student(String id, int marks) {
        this.id = id;
        this.marks = marks;
    }
    
    @Override
    public int compareTo(Student s) {
        return s.marks - this.marks;
    }
}

public class CallableFutureTest {
    
    Callable<List<String>> getc(String fname) {
        return new Callable<List<String>>() {
            Student lineToStudent(String line) {
                String[] data = line.split(" ");
                return new Student(data[0], Integer.parseInt(data[1]));
            }
            
            @Override
            public List<String> call() throws Exception {
                BufferedReader reader = new BufferedReader(new FileReader(fname));
    			String line = reader.readLine();
    			ArrayList<Student> students = new ArrayList();
    			while (line != null) {
                    students.add(lineToStudent(line));
                    line = reader.readLine();
    			}
                Collections.sort(students);
                
    			ArrayList<String> names = new ArrayList();
    			int br = 5;
                for(Student s: students) {
                    if(br <= 0) break;
                    names.add(s.id);
                    br--;
                }
                return names;
            }
        };
    }

	public static void main(String[] args) throws Exception {
        CallableFutureTest cftest = new CallableFutureTest();
        String[] fs = {"maths.txt", "chemistry.txt", "physics.txt"};
        int MAX_T = 3;
        ExecutorService pool = Executors.newFixedThreadPool(MAX_T);
        TreeMap<String, Integer> m = new TreeMap();
        for(int i = 0; i < fs.length; i++) {
            Future<List<String>> fl = pool.submit(cftest.getc(fs[i]));
            for(String s: fl.get()) {
                if(m.containsKey(s)) {
                    m.put(s, m.get(s)+1);
                } else {
                    m.put(s, 1);
                }
            }
        }
        
        for (Map.Entry<String, Integer> entry: m.entrySet()) {
            if(entry.getValue() == 3) {
                System.out.println(entry.getKey()); 
            }
        }
        
        pool.shutdown();
	}
}