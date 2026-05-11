namespace ASCII_Minesweeper.Core {
    public class Grid {
        public List<List<Plot>> plots = new();
        public int rows = 9;
        public int columns = 9;
        public int bombs = 10;

        /// <summary>
        /// Initializes a new instance of the Grid class with specified rows, columns, and bombs.
        /// </summary>
        public void CreateGrid() {
            for (int i = 0; i < this.rows; i++) {
                this.plots.Add(new List<Plot>());
                for (int j = 0; j < this.columns; j++) {
                    this.plots[i].Add(new Plot(i, j));
                }
            }
            for (int i = 0; i < this.bombs; i++)
                this.PlaceBomb();
            for (int i = 0; i < this.rows; i++) {
                for (int j = 0; j < this.columns; j++) {
                    Plot value = this.plots[i][j];
                    if (value.content == "*")
                        UpdateValues(i, j);
                }
            }
            
        }

        /// <summary>
        /// Places a bomb at a random location on the grid.
        /// If the randomly selected plot already contains a bomb, it recursively calls itself to find a
        /// new location.
        /// </summary>
        public void PlaceBomb() {
            int row = new Random().Next(0, this.rows);
            int col = new Random().Next(0, this.columns);
            Plot plot = this.plots[row][col];
            if (!(plot.content == "*")) 
                plot.content = "*";
            else
                this.PlaceBomb();
        }

        /// <summary>
        /// Parses a string value to an integer and returns it as a string.
        /// </summary>
        /// <param name="value">The string value to parse.</param>
        /// <returns>The parsed integer value as a string.</returns>
        public static string ParseToValue(string value) {
            return int.Parse(value).ToString();
        }

        /// <summary>
        /// Updates the values of the plots in the top and bottom rows relative to the current plot
        /// based on the column index.
        /// </summary>
        /// <param name="currentRow">The current row of plots.</param>
        /// <param name="col">The column index of the current plot.</param>
        public void UpdateTopAndBottomRowValues(List<Plot> currentRow, int col) {
            if (col - 1 > -1)
                currentRow[col - 1].content = UpdateValue(currentRow[col - 1].content);
            currentRow[col].content = UpdateValue(currentRow[col].content);
            if (9 > col + 1)
                currentRow[col + 1].content = UpdateValue(currentRow[col + 1].content);
        }
        
        /// <summary>
        /// Updates the value of a plot based on its current value.
        /// If the value is "*", it remains unchanged; otherwise, it increments the value by 1.
        /// </summary>
        /// <param name="value">The current value of the plot.</param>
        /// <returns>The updated value as a string.</returns>
        public string UpdateValue(string value) {
            if (!(value == "*"))
                return (int.Parse(value) + 1).ToString();
            return "*";
        }

        /// <summary>
        /// Updates the values of the plots in the grid based on the specified row and column indices
        /// and updates the values of the plots in the top and bottom rows relative to the current plot.
        /// </summary>
        /// <param name="row">The row index of the current plot.</param>
        /// <param name="col">The column index of the current plot.</param>
        public void UpdateValues(int row, int col) {
            List<Plot> currentRow;
            if (row - 1 > -1) {
                currentRow = this.plots[row - 1];
                this.UpdateTopAndBottomRowValues(currentRow, col);
            }
            currentRow = this.plots[row];
            if (col - 1 > -1)
                currentRow[col - 1].content = UpdateValue(currentRow[col - 1].content);
            if (9 > col + 1)
                currentRow[col + 1].content = UpdateValue(currentRow[col + 1].content);
            if (9 > row + 1) {
                currentRow = this.plots[row + 1];
                this.UpdateTopAndBottomRowValues(currentRow, col);
            }
        }

        /// <summary>
        /// Prints the current state of the game board to the console.
        /// </summary>
        public void PrintBoard() {
            Console.Clear();
            string leadingSpaces = " ".PadRight(this.rows.ToString().Length + 1, ' ');
            Console.WriteLine(leadingSpaces + "  A   B   C   D   E   F   G   H   I");
            Console.WriteLine(leadingSpaces + "╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗");
            for (int i = 0; i < this.rows; i++) {
                Console.Write(i.ToString().PadRight(this.rows.ToString().Length + 1, ' ') + "║");
                for (int j = 0; j < this.columns; j++) {
                    Console.Write(" " + this.plots[i][j].GetValue() + " ║");
                }
                if (!(i == this.columns - 1))
                    Console.Write("\n" + leadingSpaces + "╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣\n");
            }
            Console.WriteLine("\n" + leadingSpaces + "╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝");
        }
    }
}