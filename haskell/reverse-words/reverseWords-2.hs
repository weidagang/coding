{-# LANGUAGE OverloadedStrings #-}

import qualified Data.Text as T
import qualified Data.List as L

reverseWords = T.intercalate " " . L.reverse . T.splitOn " "

main = print $ reverseWords "I love programming with Haskell"

