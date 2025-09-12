'''
• Name of program contained in the file: EECS 348 Assignment 2
• Brief description of the program: Recursive program that solves sudoku
• Inputs: puzzle.txts
• Output:  File name, puzzle it prints out, solution to the puzzle printed out
• Author’s full name: Mariska Rai
• Creation date: 09/09/25
- other sources- Claude
'''

class SudokuSolver:
    #so this method here is going to read the txt file, open and clean the format into usuable data
    #its going to deal with the reading, string parsing and work with a cleaner 2d data
    def __init__(self, filename): #to hold our puzzle file and also read the text 
        self.board = [] #empty grid to hold our 9x9 puzzle, store it as 2d list

        with open(filename, 'r') as file: #open the file
            for line in file: #go through each line in the file
                row = [] #make a new row for each line
                for val in line.strip().split(): #split the line into values
                    #now im going to convert _ to 0 instead so its easier for later process (idea from claude)
                    if val == "_": #if the value is underscore, make it 0
                        row.append(0)
                    else:
                        row.append(int(val)) #otherwise just make it an int
                self.board.append(row) #add the row to the board

        
    def display_grid(self):
        #the purpose of this is to take the 2dlist and display it as human readable
        # Print grid with borders
        for row in self.board: #go through each row
            print(" ".join(str(val) if val != 0 else "_" for val in row))  # print each value, show _ for 0


        #the purpose is to check if its a legal move, if i put a number here does it break the rules?
    def is_valid_move(self, row, column, num):
        #row rule: row can only have 1-9 once, if row 0 has a 5 then we cant put another 5 in that row
        if num in self.board[row]: #check if num is already in the row
            return False 
        
        for r in range(9): #check the column for the number
            if self.board[r][column] == num: #if the row and column have the number
                return False #then return false since its already there
            
        start_row = (row//3) * 3 #find the start of the 3x3 block
        start_column = (column //3) *3

        for r in range(start_row, start_row + 3): # loop through the rows of the 3x3 box
            for c in range(start_column, start_column + 3): # loop through the columns of the 3x3 box
                if self.board[r][c] == num:  # check if the number is already in this 3x3 box
                    return False  # if it is, then it's not a valid move so return false
        return True # if we checked the whole box and didn't find the number, it's a valid move

        
        # Check row, column, 3x3 block
        
    def find_empty_cell(self): #purpose of this is to find a cell thats empty or return the 
        for row in range(9): #go through every row
            for column in range(9): #go through every column
                if self.board[row][column] == 0: #if cell is 0, it's empty
                    return (row,column) #return the position
        return None #if no empty cell return None
        
    def solve_recursive(self ):
        empty_spot = self.find_empty_cell() #find the next empty cell
        if empty_spot is None: #if no empty spot puzzle is solved
            return True
        row, column = empty_spot #get the row and column

        for num in range(1,10): #try numbers 1-9
            if self.is_valid_move(row, column, num): #check if it's valid
                self.board[row][column] = num #put the number in
                if self.solve_recursive(): #recursively try to solve the rest
                    return True
                else:
                    self.board[row][column] = 0 #if it didn't work, reset to 0
        return False #if no number works, return false

    def solve(self):
        return self.solve_recursive() #just call the recursive solver
    
def main(): #claude helped with printing it in a nice manner or else it was a big fat mess
    puzzles = ["puzzle1.txt","puzzle2.txt", "puzzle3.txt","puzzle4.txt","puzzle5.txt"] #list of puzzle files

    for puzzle in puzzles: #go through each puzzle
        print("-" * 30) #print a separator
        print(f"Puzzle file: {puzzle}") #show which file
        print("Initial puzzle:") #label
        solver = SudokuSolver(puzzle) #make a solver for this puzzle
        solver.display_grid() #show the puzzle
        print()  # Blank line between puzzle and solution
        if solver.solve(): #try to solve it
            print("Solution:") #label
            solver.display_grid() #show the solution
        else:
            print("No solution found") #if it can't be solved
        print("-" * 30) #separator
        print()  # Extra space between puzzles


if __name__ == "__main__":
    main() #run the main

