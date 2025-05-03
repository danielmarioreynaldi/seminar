import subprocess
import os

failed = 0
total = 0

def extract_functions_from_ctags(c_file):
    result = subprocess.run(
        ['ctags', '-x', '--c-kinds=f', c_file],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )

    functions = []
    for line in result.stdout.splitlines():
        parts = line.split()
        if len(parts) >= 4:
            function_name = parts[0]
            functions.append(function_name)

    return functions

def run_esbmc(file, functions):
    for function in functions:
        result = subprocess.run(
            ['esbmc', file, '--function', function, '--unwind', '5', '--timeout', '1'],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )
        global total
        total += 1
        
        if (result.stderr.find("VERIFICATION SUCCESSFUL") != -1):
            print(function, ": Success")
        elif (result.stderr.find("VERIFICATION FAILED") != -1):
            global failed
            failed += 1
            print(function , ": Failed")
        else:
            pass
            #print(function, "No result")
    


if __name__ == "__main__":
    files = os.listdir(".")
    c_files = [f for f in files if f.endswith(".c")]

    for c_file in c_files:
        functions = extract_functions_from_ctags(c_file)  
        print(c_file, ":")      
        run_esbmc(c_file, functions)
    
    print("Failed percentage: ", (failed/total)*100)
