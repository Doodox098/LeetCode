class Solution:
    def numUniqueEmails(self, emails: list[str]) -> int:
        new_emails = list('')
        ans = 0
        for s in emails:
            cur = s.split('@')
            cur[0] = ''.join(cur[0].split('+')[0].split('.'))
            cur = '@'.join(cur)
            try:
                new_emails.index(cur)
            except ValueError:
                new_emails.append(cur)
                ans += 1
        return ans


inp_str = input().split(' ')
print(inp_str)
ans = Solution()
print(ans.numUniqueEmails(inp_str))
# test.email+alex@leetcode.com test.e.mail+bob.cathy@leetcode.com testemail+david@lee.tcode.com