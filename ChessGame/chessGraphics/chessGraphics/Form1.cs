private void paintBoard(string board)
{
    int i, j, z = 0;

    matBoard = new Button[BOARD_SIZE, BOARD_SIZE];

    btnBoard.FlatAppearance.MouseOverBackColor = Color.LightGray;

    Button newBtn;
    Point pnt;

    int currentWidth = btnBoard.Location.X;
    int currentHeight = btnBoard.Location.Y;

    bool isColBlack = true;
    bool isRowBlack = true;

    this.SuspendLayout();

    lblCurrentPlayer.Text = isCurPlWhite ? "White" : "Black";

    for (i = 0; i < BOARD_SIZE; i++)
    {
        currentWidth = btnBoard.Location.X;
        isColBlack = isRowBlack;

        for (j = 0; j < BOARD_SIZE; j++)
        {
            newBtn = new Button();
            matBoard[i, j] = newBtn;

            newBtn.FlatAppearance.MouseOverBackColor = btnBoard.FlatAppearance.MouseOverBackColor;
            newBtn.BackColor = isColBlack ? Color.Gray : Color.White;  //default square color
            newBtn.FlatAppearance.BorderColor = btnBoard.FlatAppearance.BorderColor;
            newBtn.FlatAppearance.BorderSize = btnBoard.FlatAppearance.BorderSize;
            newBtn.FlatStyle = btnBoard.FlatStyle;

            newBtn.Size = new System.Drawing.Size(btnBoard.Width, btnBoard.Height);
            newBtn.Tag = new Square(i, j);
            pnt = new Point(currentWidth, currentHeight);
            newBtn.Location = pnt;
            newBtn.BackgroundImageLayout = ImageLayout.Stretch;

            newBtn.BackgroundImage = getImageBySign(board[z]);

            newBtn.Click += lastlbl_Click;

            Controls.Add(newBtn);

            // Example of how to change square colors if necessary
            // For example, you can change color of a square that contains a piece of your color
            if (_boardStatus[i][j] != null && _boardStatus[i][j].iswhite() == isCurPlWhite)
            {
                newBtn.BackColor = Color.LightBlue;  // Change color of squares with your pieces
            }

            currentWidth += btnBoard.Width;
            isColBlack = !isColBlack;
            z++;
        }

        isRowBlack = !isRowBlack;
        currentHeight += btnBoard.Height;
    }

    Controls.Remove(btnBoard);
    this.ResumeLayout(false);
}
