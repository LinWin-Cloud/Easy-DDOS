import os

if __name__ == "__main__":
    open_lib = open("lib.txt" , "r")
    read_lib = read(open_lib)

    split_lib = read_lib.split("\n")
    for i in split_lib:
        os.system("sudo apt install " + i)

    print("[INFO] FINISHED INSTALL")