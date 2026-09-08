#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    int assign;
    int algo;

    const string BASE = "..";

    while (true)
    {
        cout << "\n***************************************" << endl;
        cout << "        Assignment Selection           " << endl;
        cout << "***************************************" << endl;
        cout << "1. Assignment 01" << endl;
        cout << "2. Assignment 02" << endl;
        cout << "3. Assignment 03" << endl;
        cout << "4. Assignment 04" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter Assignment Number: ";

        cin >> assign;

        // ============================================================
        // ASSIGNMENT 01
        // ============================================================

        if (assign == 1)
        {
            cout << "\n***************************************" << endl;
            cout << "        Assignment 01 Algorithms       " << endl;
            cout << "***************************************" << endl;
            cout << "1. All Algorithms" << endl;
            cout << "2. CSR" << endl;
            cout << "3. GEMM" << endl;
            cout << "4. Back to Main Menu" << endl;
            cout << "Enter Algorithm: ";

            cin >> algo;

            if (algo == 1)
            {
                cout << "\n=======================================" << endl;
                cout << "       Running All Algorithms          " << endl;
                cout << "=======================================\n" << endl;

                string cmd;

                // ---------------- CSR ----------------

                system("pkill -f csr 2>/dev/null");

                cmd ="cd " + BASE +"/Assignment_01 && ""mkdir -p executables";
                system(cmd.c_str());

                cmd ="cd " + BASE +"/Assignment_01 && ""g++ -std=c++17 -I src ""driver/driver_csr.cpp ""src/csr.cpp ""-o executables/csr";

                if (system(cmd.c_str()) != 0)
                {
                    cout << "Error compiling CSR." << endl;
                    return 1;
                }

                cout << "\nRunning CSR...\n" << endl;

                cmd ="cd " + BASE +"/Assignment_01 && ""./executables/csr";

                if (system(cmd.c_str()) != 0)
                {
                    cout << "Error running CSR." << endl;
                    return 1;
                }

                // ---------------- GEMM ----------------

                system("pkill -f matrix 2>/dev/null");

                cmd ="cd " + BASE +"/Assignment_01 && " "g++ -std=c++17 -I src " "driver/driver_gemm.cpp " "src/gemm.cpp " "src/B_GEMM.cpp " "-o executables/matrix";

                if (system(cmd.c_str()) != 0)
                {
                    cout << "Error compiling GEMM." << endl;
                    return 1;
                }

                cout << "\nRunning GEMM...\n" << endl;

                cmd ="cd " + BASE + "/Assignment_01 && " "./executables/matrix";

                if (system(cmd.c_str()) != 0)
                {
                    cout << "Error running GEMM." << endl;
                    return 1;
                }

                cout << endl;
                cout << "All Assignment 01 algorithms executed successfully."<< endl;
                cout << endl;
            }

            else if (algo == 2)
            {
                system("pkill -f csr 2>/dev/null");

                string cmd ="cd " + BASE +"/Assignment_01 && ""mkdir -p executables";

                system(cmd.c_str());

                cmd ="cd " + BASE + "/Assignment_01 && " "g++ -std=c++17 -I src " "driver/driver_csr.cpp " "src/csr.cpp " "-o executables/csr";

                if (system(cmd.c_str()) != 0)
                {
                    cout << "Error compiling CSR." << endl;
                    return 1;
                }

                cout << "\nRunning CSR...\n" << endl;

                cmd = "cd " + BASE + "/Assignment_01 && " "./executables/csr";

                if (system(cmd.c_str()) != 0)
                {
                    cout << "Error running CSR." << endl;
                    return 1;
                }
            }

            else if (algo == 3)
            {
                system("pkill -f matrix 2>/dev/null");

                string cmd = "cd " + BASE + "/Assignment_01 && " "mkdir -p executables";

                system(cmd.c_str());

                cmd = "cd " + BASE +  "/Assignment_01 && "  "g++ -std=c++17 -I src "  "driver/driver_gemm.cpp "  "src/gemm.cpp "  "src/B_GEMM.cpp "  "-o executables/matrix";

                if (system(cmd.c_str()) != 0)
                {
                    cout << "Error compiling GEMM." << endl;
                    return 1;
                }

                cout << "\nRunning GEMM...\n" << endl;

                cmd = "cd " + BASE + "/Assignment_01 && " "./executables/matrix";

                if (system(cmd.c_str()) != 0)
                {
                    cout << "Error running GEMM." << endl;
                    return 1;
                }
            }

            else if (algo == 4)
            {
                continue;
            }

            else
            {
                cout << "\nInvalid algorithm choice!" << endl;
            }
        }

        // ============================================================
        // ASSIGNMENT 02
        // ============================================================

        else if (assign == 2)
        {
            cout << "\n***************************************" << endl;
            cout << "        Assignment 02 Algorithms       " << endl;
            cout << "***************************************" << endl;
            cout << "1. All Algorithms" << endl;
            cout << "2. Bellman-Ford" << endl;
            cout << "3. Floyd-Warshall" << endl;
            cout << "4. Back to Main Menu" << endl;
            cout << "Enter Algorithm: ";

            cin >> algo;

            if (algo == 1)
            {
                cout << "\n=======================================" << endl;
                cout << "       Running All Algorithms          " << endl;
                cout << "=======================================\n" << endl;

                string cmd;

                // ---------------- Bellman-Ford ----------------

                system("pkill -f bellman 2>/dev/null");

                cmd ="cd " + BASE + "/Assignment_02 && " "mkdir -p executables";

                system(cmd.c_str());

                cmd ="cd " + BASE +"/Assignment_02 && ""g++ -std=c++17 -I src ""driver/Bellmanford_driver.cpp ""src/csr.cpp ""src/Bellmanford.cpp ""-o executables/bellman";

                if (system(cmd.c_str()) != 0)
                {
                    cout << "Error compiling Bellman-Ford." << endl;
                    return 1;
                }

                cout << "\nRunning Bellman-Ford...\n" << endl;

                cmd ="cd " + BASE +"/Assignment_02 && ""./executables/bellman";

                if (system(cmd.c_str()) != 0)
                {
                    cout << "Error running Bellman-Ford." << endl;
                    return 1;
                }

                // ---------------- Floyd-Warshall ----------------

                system("pkill -f floyd 2>/dev/null");

                cmd ="cd " + BASE + "/Assignment_02 && " "g++ -std=c++17 -I src " "driver/Floyd_driver.cpp " "src/csr.cpp " "src/FloydWarshall.cpp " "-o executables/floyd";

                if (system(cmd.c_str()) != 0)
                {
                    cout << "Error compiling Floyd-Warshall." << endl;
                    return 1;
                }

                cout << "\nRunning Floyd-Warshall...\n" << endl;

                cmd = "cd " + BASE + "/Assignment_02 && " "./executables/floyd";

                if (system(cmd.c_str()) != 0)
                {
                    cout << "Error running Floyd-Warshall." << endl;
                    return 1;
                }

                cout << endl;
                cout << "All Assignment 02 algorithms executed successfully."<< endl;
                cout << endl;
            }

            else if (algo == 2)
            {
                system("pkill -f bellman 2>/dev/null");

                string cmd ="cd " + BASE + "/Assignment_02 && " "mkdir -p executables";

                system(cmd.c_str());

                cmd = "cd " + BASE + "/Assignment_02 && " "g++ -std=c++17 -I src " "driver/Bellmanford_driver.cpp " "src/csr.cpp " "src/Bellmanford.cpp " "-o executables/bellman";

                if (system(cmd.c_str()) != 0)
                {
                    cout << "Error compiling Bellman-Ford." << endl;
                    return 1;
                }

                cout << "\nRunning Bellman-Ford...\n" << endl;

                cmd ="cd " + BASE +"/Assignment_02 && ""./executables/bellman";

                if (system(cmd.c_str()) != 0)
                {
                    cout << "Error running Bellman-Ford." << endl;
                    return 1;
                }
            }

            else if (algo == 3)
            {
                system("pkill -f floyd 2>/dev/null");

                string cmd ="cd " + BASE +"/Assignment_02 && ""mkdir -p executables";

                system(cmd.c_str());

                cmd = "cd " + BASE + "/Assignment_02 && " "g++ -std=c++17 -I src " "driver/Floyd_driver.cpp ""src/csr.cpp " "src/FloydWarshall.cpp " "-o executables/floyd";

                if (system(cmd.c_str()) != 0)
                {
                    cout << "Error compiling Floyd-Warshall." << endl;
                    return 1;
                }

                cout << "\nRunning Floyd-Warshall...\n" << endl;

                cmd ="cd " + BASE +"/Assignment_02 && ""./executables/floyd";

                if (system(cmd.c_str()) != 0)
                {
                    cout << "Error running Floyd-Warshall." << endl;
                    return 1;
                }
            }

            else if (algo == 4)
            {
                continue;
            }

            else
            {
                cout << "\nInvalid algorithm choice!" << endl;
            }
        }

        // ============================================================
        // ASSIGNMENT 03
        // ============================================================

        else if (assign == 3)
        {
            cout << "\n***************************************" << endl;
            cout << "        Assignment 03 Algorithms       " << endl;
            cout << "***************************************" << endl;
            cout << "1. Run Prim and Kruskal" << endl;
            cout << "2. Back to Main Menu" << endl;
            cout << "Enter Option: ";

            cin >> algo;

            if (algo == 1)
            {
                cout << "\n=======================================" << endl;
                cout << "       Running MST Algorithms          " << endl;
                cout << "=======================================\n" << endl;

                system("pkill -f assignment3 2>/dev/null");

                string cmd = "cd " + BASE +" && mkdir -p Assignment_03/Executables";

                system(cmd.c_str());

                cmd =  "cd " + BASE +  " && g++ -std=c++17 -I common_csr "  "common_csr/csr.cpp "  "Assignment_03/src/kruskal.cpp "  "Assignment_03/src/prim.cpp "  "Assignment_03/driver/driver.cpp "  "-o Assignment_03/Executables/assignment3";

                if (system(cmd.c_str()) != 0)
                {
                    cout << "Error compiling Assignment 03." << endl;
                    return 1;
                }

                cout << "\nRunning Prim and Kruskal...\n" << endl;

                cmd =
                    "cd " + BASE +
                    " && ./Assignment_03/Executables/assignment3";

                if (system(cmd.c_str()) != 0)
                {
                    cout << "Error running Assignment 03." << endl;
                    return 1;
                }

                cout << endl;
                cout << "Assignment 03 executed successfully." << endl;
                cout << "Prim and Kruskal completed." << endl;
                cout << endl;
            }

            else if (algo == 2)
            {
                continue;
            }

            else
            {
                cout << "\nInvalid option!" << endl;
            }
        }

        // ============================================================
        // ASSIGNMENT 04
        // ============================================================

        else if (assign == 4)
        {
            cout << "\n***************************************" << endl;
            cout << "        Assignment 04 Algorithms       " << endl;
            cout << "***************************************" << endl;
            cout << "1. PageRank" << endl;
            cout << "2. Vertex Coloring" << endl;
            cout << "3. Run Both" << endl;
            cout << "4. Back to Main Menu" << endl;
            cout << "Enter Algorithm: ";

            cin >> algo;

            // ========================================================
            // PAGE RANK
            // ========================================================

            if (algo == 1)
            {
                cout << "\n=======================================" << endl;
                cout << "          Running PageRank             " << endl;
                cout << "=======================================\n" << endl;

                system("pkill -f pagerank 2>/dev/null");

                string cmd;

                // Create executable and output directories
                cmd =    "cd " + BASE +  "/Assignment_04 && "    "mkdir -p Executables outputs/pagerank";

                system(cmd.c_str());

                // Compile PageRank
                cmd = "cd " + BASE + " && g++ -std=c++17 -I common_csr " "Assignment_04/src/pagerank.cpp " "Assignment_04/driver/driver_pagerank.cpp " "common_csr/csr.cpp " "-o Assignment_04/Executables/pagerank";

                if (system(cmd.c_str()) != 0)
                {
                    cout << "Error compiling PageRank." << endl;
                    return 1;
                }

                cout << "\nRunning PageRank on all test file" << endl;

                // Run all PageRank test files
                cmd =  "cd " + BASE +  " && for file in Assignment_04/tests/PageRank_tests/*.txt; "  "do "  "name=$(basename \"$file\" .txt); "  "echo \"Running $name.txt...\"; "  "./Assignment_04/Executables/pagerank \"$file\" "  "> \"Assignment_04/outputs/pagerank/${name}_output.txt\"; " "done";

                if (system(cmd.c_str()) != 0)
                {
                    cout << "Error running PageRank." << endl;
                    return 1;
                }

                cout << endl;
                cout << "PageRank completed successfully." << endl;
                cout << "Outputs saved in:" << endl;
                cout << BASE << "/Assignment_04/outputs/pagerank"<< endl;
                cout << endl;
            }

            // ========================================================
            // VERTEX COLORING
            // ========================================================

            else if (algo == 2)
            {
                cout << "\n=======================================" << endl;
                cout << "       Running Vertex Coloring         " << endl;
                cout << "=======================================\n" << endl;

                system("pkill -f vertex_coloring 2>/dev/null");

                string cmd;

                // Create executable and output directories
                cmd = "cd " + BASE + "/Assignment_04 && " "mkdir -p Executables outputs/vertex_coloring";

                system(cmd.c_str());

                // Compile Vertex Coloring
                cmd = "cd " + BASE + " && g++ -std=c++17 -I common_csr " "Assignment_04/src/vertex_coloring.cpp " "Assignment_04/driver/driver_vertex_coloring.cpp " "common_csr/csr.cpp " "-o Assignment_04/Executables/vertex_coloring";

                if (system(cmd.c_str()) != 0)
                {
                    cout << "Error compiling Vertex Coloring." << endl;
                    return 1;
                }

                cout << "\nRunning Vertex Coloring on all test files..."
                     << endl;

                // Run all Vertex Coloring test files
                cmd = "cd " + BASE +" && for file in Assignment_04/tests/VertexColoring_tests/*.txt; ""do " "name=$(basename \"$file\" .txt); " "echo \"Running $name.txt...\"; " "./Assignment_04/Executables/vertex_coloring \"$file\" " "> \"Assignment_04/outputs/vertex_coloring/${name}_output.txt\"; " "done";

                if (system(cmd.c_str()) != 0)
                {
                    cout << "Error running Vertex Coloring." << endl;
                    return 1;
                }

                cout << endl;
                cout << "Vertex Coloring completed successfully." << endl;
                cout << "Outputs saved in:" << endl;
                cout << BASE << "/Assignment_04/outputs/vertex_coloring" << endl;
                cout << endl;
            }

            // ========================================================
            // RUN BOTH
            // ========================================================

            else if (algo == 3)
            {
                cout << "\n=======================================" << endl;
                cout << "       Running All Algorithms          " << endl;
                cout << "=======================================\n" << endl;

                string cmd;

                // ====================================================
                // PAGE RANK
                // ====================================================

                system("pkill -f pagerank 2>/dev/null");

                cmd = "cd " + BASE + "/Assignment_04 && " "mkdir -p Executables outputs/pagerank";

                system(cmd.c_str());

                cout << "\nCompiling PageRank..." << endl;

                cmd = "cd " + BASE + " && g++ -std=c++17 -I common_csr " "Assignment_04/src/pagerank.cpp " "Assignment_04/driver/driver_pagerank.cpp " "common_csr/csr.cpp " "-o Assignment_04/Executables/pagerank";

                if (system(cmd.c_str()) != 0)
                {
                    cout << "Error compiling PageRank." << endl;
                    return 1;
                }

                cout << "Running PageRank...\n" << endl;

                cmd =  "cd " + BASE +  " && for file in Assignment_04/tests/PageRank_tests/*.txt; "  "do "  "name=$(basename \"$file\" .txt); "  "echo \"Running $name.txt...\"; "  "./Assignment_04/Executables/pagerank \"$file\" "  "> \"Assignment_04/outputs/pagerank/${name}_output.txt\"; "  "done";

                if (system(cmd.c_str()) != 0)
                {
                    cout << "Error running PageRank." << endl;
                    return 1;
                }

                // ====================================================
                // VERTEX COLORING
                // ====================================================

                system("pkill -f vertex_coloring 2>/dev/null");

                cmd ="cd " + BASE +"/Assignment_04 && ""mkdir -p Executables outputs/vertex_coloring";

                system(cmd.c_str());

                cout << "\nCompiling Vertex Coloring..." << endl;

                cmd =  "cd " + BASE +  " && g++ -std=c++17 -I common_csr "  "Assignment_04/src/vertex_coloring.cpp "  "Assignment_04/driver/driver_vertex_coloring.cpp "  "common_csr/csr.cpp "  "-o Assignment_04/Executables/vertex_coloring";

                if (system(cmd.c_str()) != 0)
                {
                    cout << "Error compiling Vertex Coloring." << endl;
                    return 1;
                }

                cout << "Running Vertex Coloring...\n" << endl;

                cmd =  "cd " + BASE +  " && for file in Assignment_04/tests/VertexColoring_tests/*.txt; "  "do "  "name=$(basename \"$file\" .txt); "  "echo \"Running $name.txt...\"; "  "./Assignment_04/Executables/vertex_coloring \"$file\" "  "> \"Assignment_04/outputs/vertex_coloring/${name}_output.txt\"; "  "done";

                if (system(cmd.c_str()) != 0)
                {
                    cout << "Error running Vertex Coloring." << endl;
                    return 1;
                }

                cout << endl;
                cout << "All Assignment 04 algorithms executed successfully." << endl;
                cout << endl;
            }

            else if (algo == 4)
            {
                continue;
            }

            else
            {
                cout << "\nInvalid algorithm choice!" << endl;
            }
        }

        // ============================================================
        // EXIT
        // ============================================================

        else if (assign == 5)
        {
            cout << "\nExiting..." << endl;
            break;
        }

        else
        {
            cout << "\nInvalid assignment choice!" << endl;
        }
    }

    return 0;
}