{git常用操作

	git reset --mixed	*****	//commit 之后，回到之前的版本
	{下载代码
		git clone git://github.com/schacon/grit.git
	}
	
	{检查当前文件下的状态
		git status
	}
	
	{提交流程
		git add file	//跟踪文件
		git commit file	//
		git push file -m "message"	//
	}
	
	{忽略某些文件
		我们可以创建一个名为 .gitignore 的文件
		
		所有空行或者以注释符号 ＃ 开头的行都会被 Git 忽略。
		可以使用标准的 glob 模式匹配。 * 匹配模式最后跟反斜杠（/）说明要忽略的是目录。 * 要忽略指定模式以外的文件或目录，可以在模式前加上惊叹号（!）取反。
		所谓的 glob 模式是指 shell 所使用的简化了的正则表达式。星号（*）匹配零个或多个任意字符；[abc] 匹配任何一个列在方括号中的字符（这个例子要么匹配一个 a，要么匹配一个 b，要么匹配一个 c）；问号（?）只匹配一个任意字符；如果在方括号中使用短划线分隔两个字符，表示所有在这两个字符范围内的都可以匹配（比如[0-9] 表示匹配所有 0 到 9 的数字）。

		我们再看一个 .gitignore 文件的例子：

		# 此为注释 – 将被 Git 忽略
		*.a       # 忽略所有 .a 结尾的文件
		!lib.a    # 但 lib.a 除外
		/TODO     # 仅仅忽略项目根目录下的 TODO 文件，不包括 subdir/TODO
		build/    # 忽略 build/ 目录下的所有文件
		doc/*.txt # 会忽略 doc/notes.txt 但不包括 doc/server/arch.txt*/
	}
	
	{差异比较
		git diff file //显示是显示还没有暂存起来的改动
		
		若要看已经暂存起来的文件和上次提交时的快照之间的差异，可以用 git diff --cached 命令。
		git diff --cached file
	}
	
	{移除文件
		git rm file
	}
	
	{移动文件
		$ git mv file_from file_to
		相当于
		mv file_from file_to
		$ git rm file_from
		$ git add file_to
	}
	
	{查看提交历史
		git log
		
		git log -p -2
		我们常用 -p 选项展开显示每次提交的内容差异，用 -2 则仅显示最近的两次更新：
		
		git log --pretty=
			oneline	//将每个提交放在一行显示
			short	//commit第一行，message第二行
			full	//比short详细，commit，author，message
			fuller	//比full详细，commit，author，authorDate，message
			format	//自定义格式
				git log --pretty=format:"%h - %an, %ar : %s"
				%H	提交对象（commit）的完整哈希字串
				%h	提交对象的简短哈希字串
				%T	树对象（tree）的完整哈希字串
				%t	树对象的简短哈希字串
				%P	父对象（parent）的完整哈希字串
				%p	父对象的简短哈希字串
				%an	作者（author）的名字
				%ae	作者的电子邮件地址
				%ad	作者修订日期（可以用 -date= 选项定制格式）
				%ar	作者修订日期，按多久以前的方式显示
				%cn	提交者(committer)的名字
				%ce	提交者的电子邮件地址
				%cd	提交日期
				%cr	提交日期，按多久以前的方式显示
				%s	提交说明
		-p 按补丁格式显示每个更新之间的差异。
		--stat 显示每次更新的文件修改统计信息。
		--shortstat 只显示 --stat 中最后的行数修改添加移除统计。
		--name-only 仅在提交信息后显示已修改的文件清单。
		--name-status 显示新增、修改、删除的文件清单。
		--abbrev-commit 仅显示 SHA-1 的前几个字符，而非所有的 40 个字符。
		--relative-date 使用较短的相对时间显示（比如，“2 weeks ago”）。
		--graph 显示 ASCII 图形表示的分支合并历史。
		--pretty 使用其他格式显示历史提交信息。可用的选项包括 oneline，short，full，fuller 和 format（后跟指定格式）。
		
		{限制输出长度
			--since 和 --until
			git log --since=2.weeks	命令列出所有最近两周内的提交：
			
			-(n)	仅显示最近的 n 条提交
			--since, --after 仅显示指定时间之后的提交。
			--until, --before 仅显示指定时间之前的提交。
			--author 仅显示指定作者相关的提交。
			--committer 仅显示指定提交者相关的提交。
		}
	}
	
	{修改最后一次提交
		git commit  --amend
	}
	
	{取消已经暂存的文件
		git reset HEAD file
	}
	
	{取消本地修改的文件
		git checkout -- file
	}
	
	{新建分支
		git branch BranchName
	}
	
	{切换分支
		git checkout BranchName
	}
	
	{分支的合并
		git checkout master	切换到master
		git merge	branch	//合并
	}
	
	{查看项目地址
		git remote -v
	}
	
	参考：http://www.open-open.com/lib/view/open1328069609436.html
	参考：http://www.open-open.com/lib/view/open1328069733264.html
	参考：http://www.open-open.com/lib/view/open1328069889514.html
}