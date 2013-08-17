module Main where

import Control.Monad.State
import Data.List((\\))

type StatePrim = StateT [Int] IO

addRelPrime :: Int -> StatePrim ()
addRelPrime n = do
  prim <- get
  let prim' = [ x | x <- prim, n  `mod` x == 0]
  if null prim'
   then put $ prim ++ [n]
   else return $ ()

computePrimesFrom :: Int -> Int -> StatePrim ()
computePrimesFrom m n
  | m >= n      = return $ ()
  | m < n    = do
    addRelPrime m
    computePrimesFrom (m + 1) n

-- -- 'testLimits'
-- --
-- testLimits :: Int -> Int -> StatePrim
-- testLimits m n = do
--   prim <- get
--   = if null prim
--                   then (2,m,n)
--                   else let lp = last prim
--                        in if lp <= m
--                           then (lp,m,n)
--                           else if lp <= n
--                                then (lp,lp,n)
--                                else (lp,lp,lp)
--   return $ (i,m',n')

printPrimes :: Int -> Int -> StatePrim ()
printPrimes m n  = do
  prim <- get
  if null prim
     then do
       computePrimesFrom 2 m
       prim' <- get
       computePrimesFrom m n
       prim'' <- get
       let result = prim'' \\ prim'
       lift $ mapM_ print result >> putStrLn ""
     else 
       let lp = last prim
       in if lp <= m
          then do 
            computePrimesFrom lp m
            prim' <- get
            computePrimesFrom m n
            prim'' <- get
            let result = prim'' \\ prim'
            lift $ mapM_ print result >> putStrLn ""
          else if lp <= n
               then do
                 r1 <- get
                 let prim' = filter (<m) r1
                 computePrimesFrom lp n
                 prim'' <- get
                 let result = prim'' \\ prim'
                 lift $ mapM_ print result >> putStrLn ""
               else do
                 r1 <- get
                 let prim'  = filter (<m) r1
                     prim'' = filter (<n) r1
                     result = prim'' \\ prim'
                 lift $ mapM_ print result >> putStrLn ""

evalPrintPrimes :: Int -> Int -> [Int] -> IO ((),[Int])
evalPrintPrimes m n st = runStateT (printPrimes m n) st

process :: Int -> [Int] -> IO ()
process 1 st = return $ ()
process n st = do
  l <- getLine
  let [m,n] = map read $ words l
  (_,st') <- evalPrintPrimes m n st
  process (n - 1) st'

main :: IO ()
main = do
  l <- getLine
  let nc = read l
  process nc []
