import System.Console.Haskeline

main :: IO ()
main = runInputT defaultSettings menu

menu :: InputT IO ()
menu = do
    outputStrLn "Select an option:"
    outputStrLn "1. List Directory"
    outputStrLn "2. Show Date"
    outputStrLn "3. Exit"
    choice <- getInputLine "Enter choice: "
    case choice of
        Just "1" -> outputStrLn "Listing directory..." >> menu
        Just "2" -> outputStrLn "Showing date..." >> menu
        Just "3" -> outputStrLn "Exiting..."
        _        -> outputStrLn "Invalid choice, try again." >> menu