#!/usr/bin/env runhaskell
import System.Process (system)
import System.Exit (ExitCode(..))
import Control.Concurrent (threadDelay)

-- Arduino parameters
boardFQBN :: String
boardFQBN = "arduino:avr:nano:cpu=atmega328old"

port :: String
port = "/dev/cu.usbserial-1420"

sketchPath :: String
sketchPath = "$PWD/build"

baudRate :: String
baudRate = "9600"

targetFile :: String
targetFile = "$PWD/build/build.ino"

-- Helper to run a shell command
runCommand :: String -> IO ()
runCommand cmd = do
    putStrLn $ "Running: " ++ cmd
    exitCode <- system cmd
    case exitCode of
        ExitSuccess -> putStrLn "Success!"
        ExitFailure code -> putStrLn $ "Failed with code: " ++ show code

-- Main function
main :: IO ()
main = do
    -- Compile the sketch
    runCommand $ "arduino-cli compile --fqbn " ++ boardFQBN ++ " --output-dir " ++ sketchPath ++ " " ++ targetFile

    -- Add a delay to allow the serial port to be ready
    threadDelay (2 * 1000000)

    -- Upload the sketch
    runCommand $ "arduino-cli upload -p " ++ port ++ " -b " ++ boardFQBN ++ " --input-dir " ++ sketchPath

    -- Final delay to allow the sketch to start
    threadDelay (2 * 1000000)