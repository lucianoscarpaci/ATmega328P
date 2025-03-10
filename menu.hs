#!/usr/bin/env runhaskell
import System.Process (system)
import System.Exit (ExitCode(..))
import System.Console.Haskeline
import Control.Monad.IO.Class (liftIO)

main :: IO ()
main = runInputT defaultSettings menu

menu :: InputT IO ()
menu = do
    outputStrLn "Select a sketch:"
    outputStrLn "1. AES"
    outputStrLn "2. Blink"
    outputStrLn "3. EEA"
    outputStrLn "4. RNG"
    outputStrLn "5. Exit"
    outputStrLn "6. Open Serial Monitor"
    choice <- getInputLine "Enter choice: "
    case choice of
        Just "1" -> liftIO (runCommand "cd ./Sketches/AES && ./flash") >> menu
        Just "2" -> liftIO (runCommand "cd ./Sketches/Blink && ./flash") >> menu
        Just "3" -> liftIO (runCommand "cd ./Sketches/EEA && ./flash") >> menu
        Just "4" -> liftIO (runCommand "cd ./Sketches/RNG && ./flash") >> menu 
        Just "5" -> outputStrLn "Exiting..."
        Just "6" -> liftIO (runCommand "screen /dev/cu.usbserial-1420 9600")
        _        -> outputStrLn "Invalid choice, try again." >> menu

-- Helper to run a shell command
runCommand :: String -> IO ()
runCommand cmd = do
    putStrLn $ "Running: " ++ cmd
    exitCode <- system cmd
    case exitCode of
        ExitSuccess -> putStrLn "Success!"
        ExitFailure code -> putStrLn $ "Failed with code: " ++ show code